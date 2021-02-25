#include "C0MultiTestGameInstance.h"

#include "Kismet/KismetSystemLibrary.h"

bool UC0MultiTestGameInstance::s_bEnableVivox = true;

UC0MultiTestGameInstance::UC0MultiTestGameInstance() :
	m_bIsVivoxInitialized(false),
	m_bIsVivoxInitializing(false),
	m_bVivoxLoggedIn(false),
	m_bIsVivoxLoggingIn(false)

	,m_VivoxVoiceClient(&static_cast<FVivoxCoreModule*>(&FModuleManager::Get().LoadModuleChecked(TEXT("VivoxCore")))->VoiceClient())

{
}

void UC0MultiTestGameInstance::Init()
{

	if (s_bEnableVivox && !UKismetSystemLibrary::IsDedicatedServer(GetWorld()))
	{
		InitializeVivox(EVivoxInit::All);
	}


	Super::Init();
}

void UC0MultiTestGameInstance::StartGameInstance()
{
	Super::StartGameInstance();


	// TODO: If logged in with Steam get the userid etc and pass that to Login instead of our temp name
	const FString TmpName = FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphens);
	LoginVivox(FString::Printf(TEXT("%s"), *TmpName));

}


VivoxCoreError UC0MultiTestGameInstance::JoinVoiceChannels(const uint8 TeamChannelToJoin, const FString& SessionID)
{
	if (!s_bEnableVivox) return VxErrorNotInitialized;

	if (!m_bVivoxLoggedIn)
	{
		return VxErrorNotLoggedIn;
	}

	// Player is already in a channel so let's change that
	if (m_bIsInVoiceChannel)
	{
		LeaveVoiceChannels();

		JoinVoiceChannels(TeamChannelToJoin, SessionID);
		return VxErrorInternalError;  // There's no error for being already in a channel so let's just throw an internal error
	}

	ensure(!m_VivoxLoggedInPlayerName.IsEmpty());

	// Create the channel name for the player to join. If the SessionID is empty we generate a random guid for the channel name so the player is put into a "private" room else put them into the actual team room
	const FString GeneratedChannelName = FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphens);
	m_VivoxChannelName = FString::Printf(TEXT("TN%d_%s"), TeamChannelToJoin, SessionID.IsEmpty() ? *FString::Printf(TEXT("G_%s"), *GeneratedChannelName) : *SessionID);

	ILoginSession& LoginSession = m_VivoxVoiceClient->GetLoginSession(m_LoggedInAccountID);
	// It's perfectly safe to add 3D properties to any channel type (they don't have any effect if the channel type is not Positional)
	ChannelId Channel = ChannelId(VIVOX_ISSUER, m_VivoxChannelName, VIVOX_DOMAIN, ChannelType::NonPositional, Channel3DProperties(8100, 270, 1.0, EAudioFadeModel::InverseByDistance));
	IChannelSession& ChannelSession = LoginSession.GetChannelSession(Channel);

	// This is insecure and should be done via game server
	const FString JoinToken = ChannelSession.GetConnectToken(VIVOX_SECRET, FTimespan::FromSeconds(TOKEN_EXPIRY));

	IChannelSession::FOnBeginConnectCompletedDelegate OnBeginConnectCompleteCallback;
	OnBeginConnectCompleteCallback.BindLambda([this, &LoginSession, &ChannelSession](VivoxCoreError Status) {
		if (VxErrorSuccess != Status)
		{
			BindChannelSessionHandlers(false, ChannelSession);
			LoginSession.DeleteChannelSession(ChannelSession.Channel());

			m_bIsInVoiceChannel = false;
		}
		else
		{
			LoginSession.SetTransmissionMode(TransmissionMode::Single);
			BindChannelSessionHandlers(true, ChannelSession);

			m_bIsInVoiceChannel = true;
		}
	});

	m_LastKnownTransmittingChannel = Channel;
	return ChannelSession.BeginConnect(true, false, true, JoinToken, OnBeginConnectCompleteCallback);
}


void UC0MultiTestGameInstance::LeaveVoiceChannels()
{

	if (!s_bEnableVivox || !m_bVivoxLoggedIn) return;

	TArray<ChannelId> ChannelSessionKeys;
	m_VivoxVoiceClient->GetLoginSession(m_LoggedInAccountID).ChannelSessions().GenerateKeyArray(ChannelSessionKeys);
	for (const ChannelId& SessionKey : ChannelSessionKeys)
	{
		ILoginSession& LoginSession = m_VivoxVoiceClient->GetLoginSession(m_LoggedInAccountID);
		IChannelSession& ChannelSession = LoginSession.GetChannelSession(SessionKey);

		ChannelSession.Disconnect();
		BindChannelSessionHandlers(false, ChannelSession);
		LoginSession.DeleteChannelSession(SessionKey);
	}

	m_LastKnownTransmittingChannel = ChannelId();
	m_bIsInVoiceChannel = false;

}

TArray<FString> UC0MultiTestGameInstance::GetConnectedClients(const FString& ChannelName) const
{

	if (!s_bEnableVivox) return {};
	IChannelSession& ChannelSession = m_VivoxVoiceClient->GetLoginSession(m_LoggedInAccountID).GetChannelSession(m_LastKnownTransmittingChannel);
	TArray<FString> clients;

	for (const auto& client : ChannelSession.Participants())
	{
		clients.Add(client.Key);
	}

	return clients;

	return {};
}

TArray<FString> UC0MultiTestGameInstance::GetClientsTalking(const FString& ChannelName) const
{

	if (!s_bEnableVivox) return {};
	TArray<FString> clients;

	IChannelSession& ChannelSession = m_VivoxVoiceClient->GetLoginSession(m_LoggedInAccountID).GetChannelSession(m_LastKnownTransmittingChannel);
	for (const auto& client : ChannelSession.Participants())
	{
		if (client.Value->SpeechDetected())
		{
			clients.Add(client.Key);
		}
	}

	return clients;

	return {};
}

void UC0MultiTestGameInstance::ToggleMuteClient(const FString& ClientToMute, bool bMute /*= true*/)
{

	IChannelSession& ChannelSession = m_VivoxVoiceClient->GetLoginSession(m_LoggedInAccountID).GetChannelSession(m_LastKnownTransmittingChannel);

	IParticipant* client = *ChannelSession.Participants().Find(ClientToMute);
	if (client)
	{
		client->SetLocalMute(bMute);
	}

}

void UC0MultiTestGameInstance::ToggleMuteSelfInput(bool bMute)
{

	m_VivoxVoiceClient->AudioInputDevices().SetMuted(bMute);

}

void UC0MultiTestGameInstance::ToggleMuteSelfOutput(bool bMute)
{

	m_VivoxVoiceClient->AudioOutputDevices().SetMuted(bMute);

}

TArray<FVivoxAudioDevice> UC0MultiTestGameInstance::GetAudioInputDevices() const
{

	TMap<FString, IAudioDevice*> devices = m_VivoxVoiceClient->AudioInputDevices().AvailableDevices();

	TArray<FVivoxAudioDevice> NewDevices;
	for (const auto& device : devices)
	{
		NewDevices.Add({device.Value->Name(), device.Value->Id()});
	}

	return NewDevices;

	return {};
}

TArray<FVivoxAudioDevice> UC0MultiTestGameInstance::GetAudioOutputDevices() const
{

	TMap<FString, IAudioDevice*> devices = m_VivoxVoiceClient->AudioOutputDevices().AvailableDevices();

	TArray<FVivoxAudioDevice> NewDevices;
	for (const auto& device : devices)
	{
		NewDevices.Add({device.Value->Name(), device.Value->Id()});
	}

	return NewDevices;

	return {};
}

void UC0MultiTestGameInstance::SetAudioInputDevice(const FString& AudioDevice)
{

	TMap<FString, IAudioDevice*> devices = m_VivoxVoiceClient->AudioInputDevices().AvailableDevices();
	m_VivoxVoiceClient->AudioInputDevices().SetActiveDevice(**devices.Find(AudioDevice));

}

void UC0MultiTestGameInstance::SetAudioOutputDevice(const FString& AudioDevice)
{

	TMap<FString, IAudioDevice*> devices = m_VivoxVoiceClient->AudioOutputDevices().AvailableDevices();
	m_VivoxVoiceClient->AudioOutputDevices().SetActiveDevice(**devices.Find(AudioDevice));

}

void UC0MultiTestGameInstance::SetAudioInputDeviceVolume(int32 NewVolume)
{

	m_VivoxVoiceClient->AudioInputDevices().SetVolumeAdjustment(FMath::Clamp<int32>(NewVolume, -50, 50));

}

void UC0MultiTestGameInstance::SetAudioOutputDeviceVolume(int32 NewVolume)
{

	m_VivoxVoiceClient->AudioOutputDevices().SetVolumeAdjustment(FMath::Clamp<int32>(NewVolume, -50, 50));

}


VivoxCoreError UC0MultiTestGameInstance::InitializeVivox(EVivoxInit logLevel)
{
	if (m_bIsVivoxInitialized || m_bIsVivoxInitializing)
	{
		return VxErrorSuccess;
	}

	VivoxConfig Config;
	Config.SetLogLevel((vx_log_level)logLevel);
	VivoxCoreError Status = m_VivoxVoiceClient->Initialize(Config);
	if (Status != VxErrorSuccess)
	{
		// Something went wrong so we should log
	}
	else
	{
		m_bIsVivoxInitialized = true;
	}

	return Status;
}

VivoxCoreError UC0MultiTestGameInstance::LoginVivox(const FString& PlayerName)
{
	if (!s_bEnableVivox) return VxErrorNotInitialized;

	if (m_bVivoxLoggedIn)
	{
		return VxErrorSuccess;
	}

	if (m_bIsVivoxLoggingIn)
	{
		return VxErrorSuccess;
	}

	if (!m_bIsVivoxInitialized)
	{
		return VxErrorNotInitialized;
	}

	if (m_VivoxVoiceClient == nullptr)
	{
		return VxErrorTargetObjectDoesNotExist;
	}

	m_VivoxLoggedInPlayerName = PlayerName;
	m_LoggedInAccountID = AccountId(VIVOX_ISSUER, m_VivoxLoggedInPlayerName, VIVOX_DOMAIN);
	ILoginSession& LoginSession = m_VivoxVoiceClient->GetLoginSession(m_LoggedInAccountID);

	ILoginSession::FOnBeginLoginCompletedDelegate OnBeginLoginCompleteCallback;
	OnBeginLoginCompleteCallback.BindLambda([this, &LoginSession](VivoxCoreError Status) {
		m_bIsVivoxLoggingIn = false;
		if (VxErrorSuccess != Status)
		{
			BindLoginSessionHandlers(false, LoginSession);
			m_LoggedInAccountID = AccountId();
			m_VivoxLoggedInPlayerName = FString();
			m_bVivoxLoggedIn = false;
		}
		else
		{
			m_bIsVivoxLoggingIn = true;
			m_bVivoxLoggedIn = true;
			BindLoginSessionHandlers(true, LoginSession);
		}
	});

	const FString LoginToken = LoginSession.GetLoginToken(VIVOX_SECRET, FTimespan::FromSeconds(TOKEN_EXPIRY));

	return LoginSession.BeginLogin(VIVOX_SERVER, LoginToken, OnBeginLoginCompleteCallback);
}


void UC0MultiTestGameInstance::LogoutVivox()
{

	if (!s_bEnableVivox) return;
	if (!m_bVivoxLoggedIn && !m_bIsVivoxLoggingIn)
	{
		return;
	}

	ILoginSession& LoginSession = m_VivoxVoiceClient->GetLoginSession(m_LoggedInAccountID);

	LoginSession.Logout();

	m_LoggedInAccountID = AccountId();
	m_VivoxLoggedInPlayerName = FString();
	m_bIsVivoxLoggingIn = false;
	m_bVivoxLoggedIn = false;

}


void UC0MultiTestGameInstance::BindLoginSessionHandlers(bool DoBind, ILoginSession& LoginSession)
{
	if (DoBind)
	{
		LoginSession.EventStateChanged.AddUObject(this, &UC0MultiTestGameInstance::OnLoginSessionStateChanged);
	}
	else
	{
		LoginSession.EventStateChanged.RemoveAll(this);
	}
}

void UC0MultiTestGameInstance::BindChannelSessionHandlers(bool DoBind, IChannelSession& ChannelSession)
{
	if (DoBind)
	{
		ChannelSession.EventAfterParticipantAdded.AddUObject(this, &UC0MultiTestGameInstance::OnChannelParticipantAdded);
		ChannelSession.EventBeforeParticipantRemoved.AddUObject(this, &UC0MultiTestGameInstance::OnChannelParticipantRemoved);
		ChannelSession.EventAfterParticipantUpdated.AddUObject(this, &UC0MultiTestGameInstance::OnChannelParticipantUpdated);
		ChannelSession.EventAudioStateChanged.AddUObject(this, &UC0MultiTestGameInstance::OnChannelAudioStateChanged);
		ChannelSession.EventTextStateChanged.AddUObject(this, &UC0MultiTestGameInstance::OnChannelTextStateChanged);
		ChannelSession.EventTextMessageReceived.AddUObject(this, &UC0MultiTestGameInstance::OnChannelTextMessageReceived);
	}
	else
	{
		ChannelSession.EventAfterParticipantAdded.RemoveAll(this);
		ChannelSession.EventBeforeParticipantRemoved.RemoveAll(this);
		ChannelSession.EventAfterParticipantUpdated.RemoveAll(this);
		ChannelSession.EventAudioStateChanged.RemoveAll(this);
		ChannelSession.EventTextStateChanged.RemoveAll(this);
		ChannelSession.EventTextMessageReceived.RemoveAll(this);
	}
}

void UC0MultiTestGameInstance::OnLoginSessionStateChanged(LoginState State)
{
	switch (State)
	{
	case LoginState::LoggedOut:
		m_LoggedInAccountID = AccountId();
		m_VivoxLoggedInPlayerName = FString();
		m_bIsVivoxLoggingIn = false;
		m_bVivoxLoggedIn = false;
		break;
	}
}

void UC0MultiTestGameInstance::OnChannelParticipantAdded(const IParticipant& Participant)
{
	ChannelId Channel = Participant.ParentChannelSession().Channel();
	UE_LOG(LogTemp, Log, TEXT("User %s has joined channel %s (self = %s)"), *Participant.Account().Name(), *Channel.Name(), Participant.IsSelf() ? TEXT("true") : TEXT("false"));
}

void UC0MultiTestGameInstance::OnChannelParticipantRemoved(const IParticipant& Participant)
{
}

void UC0MultiTestGameInstance::OnChannelParticipantUpdated(const IParticipant& Participant)
{
	if (Participant.IsSelf())
	{
		UE_LOG(LogTemp, Log, TEXT("Self Participant Updated (audio=%d, text=%d, speaking=%d)"), Participant.InAudio(), Participant.InText(), Participant.SpeechDetected());
	}
}

void UC0MultiTestGameInstance::OnChannelAudioStateChanged(const IChannelConnectionState& State)
{
}

void UC0MultiTestGameInstance::OnChannelTextStateChanged(const IChannelConnectionState& State)
{
}

void UC0MultiTestGameInstance::OnChannelTextMessageReceived(const IChannelTextMessage& Message)
{
}
