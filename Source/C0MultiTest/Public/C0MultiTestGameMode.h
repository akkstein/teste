#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "C0MultiTestGameMode.generated.h"

UCLASS()
class C0MULTITEST_API AC0MultiTestGameMode : public AGameModeBase
{
	GENERATED_BODY()

	public:
	AC0MultiTestGameMode();

	virtual void PostLogin(APlayerController* NewPlayer) override;

private:
	FString m_VivoxServerGuid;
};
