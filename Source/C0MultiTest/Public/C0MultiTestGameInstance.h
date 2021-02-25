#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "VivoxCore.h"


#include "C0MultiTestGameInstance.generated.h"
#define VIVOX_SERVER "https://mt1s.www.vivox.com/api2"
#define VIVOX_ISSUER "alanke6625-ca12-dev"
#define VIVOX_DOMAIN "mt1s.vivox.com"
#define VIVOX_SECRET "zoom277"
#define TOKEN_EXPIRY (30 * 60)

USTRUCT(Blueprintable)
struct FVivoxAudioDevice
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FString Name;

	UPROPERTY(BlueprintReadOnly)
	FString UUID;
};

enum class EVivoxInit
{
	None = -1,
	Errors = 0,
	Warnings = 1,
	Info = 2,
	Debug = 3,
	Trace = 4,
	All = 5
};

UCLASS()
class C0MULTITEST_API UC0MultiTestGameInstance : public UGameInstance
{
	GENERATED_BODY()

	static bool s_bEnableVivox;

public:
	UC0MultiTestGameInstance();

	virtual void Init() override;
	virtual void StartGameInstance() override;

	VivoxCoreError JoinVoiceChannels(const uint8 TeamChannelToJoin, const FString& SessionID = "");

	void LeaveVoiceChannels();

	UFUNCTION(BlueprintPure, Category = "Vivox")
	bool IsVivoxLoggedIn() const { return m_bVivoxLoggedIn; }

	UFUNCTION(BlueprintPure, Category = "Vivox")
	bool IsInVoiceChannel() const { return m_bIsInVoiceChannel; }

	UFUNCTION(BlueprintPure, Category = "Vivox")
	FString GetVivoxChannelName() const { return m_VivoxChannelName; }

	UFUNCTION(BlueprintPure, Category = "Vivox")
	FString GetVivoxLoggedInPlayerName() const { return m_VivoxLoggedInPlayerName; }

	UFUNCTION(BlueprintPure, Category = "Vivox")
	TArray<FString> GetConnectedClients(const FString& ChannelName) const;

	UFUNCTION(BlueprintPure, Category = "Vivox")
	TArray<FString> GetClientsTalking(const FString& ChannelName) const;

	UFUNCTION(BlueprintCallable, Category = "Vivox")
	void ToggleMuteClient(const FString& ClientToMute, bool bMute = true);

	UFUNCTION(BlueprintCallable, Category = "Vivox")
	void ToggleMuteSelfInput(bool bMute = true);

	UFUNCTION(BlueprintCallable, Category = "Vivox")
	void ToggleMuteSelfOutput(bool bMute = true);

	UFUNCTION(BlueprintPure, Category = "Vivox")
	TArray<FVivoxAudioDevice> GetAudioInputDevices() const;

	UFUNCTION(BlueprintPure, Category = "Vivox")
	TArray<FVivoxAudioDevice> GetAudioOutputDevices() const;

	UFUNCTION(BlueprintCallable, Category = "Vivox")
	void SetAudioInputDevice(const FString& AudioDevice);

	UFUNCTION(BlueprintCallable, Category = "Vivox")
	void SetAudioOutputDevice(const FString& AudioDevice);

	UFUNCTION(BlueprintCallable, Category = "Vivox")
	void SetAudioInputDeviceVolume(int32 NewVolume = 0);

	UFUNCTION(BlueprintCallable, Category = "Vivox")
	void SetAudioOutputDeviceVolume(int32 NewVolume = 0);

private:
	void LogoutVivox();


	VivoxCoreError InitializeVivox(EVivoxInit logLevel);
	VivoxCoreError LoginVivox(const FString& PlayerName);

	void BindLoginSessionHandlers(bool DoBind, ILoginSession& LoginSession);
	void BindChannelSessionHandlers(bool DoBind, IChannelSession& ChannelSession);

	/** Vivox Delegates */
	void OnLoginSessionStateChanged(LoginState State);
	void OnChannelParticipantAdded(const IParticipant& Participant);
	void OnChannelParticipantRemoved(const IParticipant& Participant);
	void OnChannelParticipantUpdated(const IParticipant& Participant);
	void OnChannelAudioStateChanged(const IChannelConnectionState& State);
	void OnChannelTextStateChanged(const IChannelConnectionState& State);
	void OnChannelTextMessageReceived(const IChannelTextMessage& Message);


	FString m_VivoxChannelName;
	FString m_VivoxLoggedInPlayerName;

	bool m_bIsVivoxInitialized;
	bool m_bIsVivoxInitializing;
	bool m_bVivoxLoggedIn;
	bool m_bIsVivoxLoggingIn;
	bool m_bIsInVoiceChannel;


	IClient* m_VivoxVoiceClient;
	AccountId m_LoggedInAccountID;
	ILoginSession* m_LoginSession;
	ChannelId m_LastKnownTransmittingChannel;

};