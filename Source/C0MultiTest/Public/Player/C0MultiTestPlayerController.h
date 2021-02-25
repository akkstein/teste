// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "C0MultiTestPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class C0MULTITEST_API AC0MultiTestPlayerController : public APlayerController
{
	GENERATED_BODY()

	public:
	UFUNCTION(Client, Unreliable)
    void ClientJoinVoice(const uint8 TeamNumber, const FString& SessionID);
};
