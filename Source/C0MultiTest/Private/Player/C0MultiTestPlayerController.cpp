// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/C0MultiTestPlayerController.h"
#include "C0MultiTestGameInstance.h"


void AC0MultiTestPlayerController::ClientJoinVoice_Implementation(const uint8 TeamNumber, const FString& SessionID)
{
	if (!IsPrimaryPlayer())
	{
		return;
	}

	if (IsLocalController())
	{
		if (UC0MultiTestGameInstance* const GI = GetWorld()->GetGameInstance<UC0MultiTestGameInstance>())
		{

			GI->JoinVoiceChannels(TeamNumber, SessionID);

		}
	}
}
