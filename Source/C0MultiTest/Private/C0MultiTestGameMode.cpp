#include "C0MultiTestGameMode.h"
#include "Player/C0MultiTestPlayerController.h"

AC0MultiTestGameMode::AC0MultiTestGameMode()
{
	m_VivoxServerGuid = FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphens);
}

void AC0MultiTestGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (AC0MultiTestPlayerController* const ConnectingPlayerController = Cast<AC0MultiTestPlayerController>(NewPlayer))
	{
		// TODO: Here you should get the PlayerState or whatever to get the players team - in Shifted we used an enum to determine teams (which is a uint8)
		ConnectingPlayerController->ClientJoinVoice(1, m_VivoxServerGuid);
	}
}