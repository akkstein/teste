// Copyright Epic Games, Inc. All Rights Reserved.

#include "VivoxExampleGameMode.h"
#include "Player/C0MultiTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AVivoxExampleGameMode::AVivoxExampleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
