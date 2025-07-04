#include "HW_GameMode.h"
#include "HW_GameState.h"
#include "HW_PlayerController.h"
#include "HW_PlayerPawn.h"

AHW_GameMode::AHW_GameMode()
{
	GameStateClass = AHW_GameState::StaticClass();
	checkf(GameStateClass, TEXT("GameStateClass is not set in GameMode!"));

	PlayerControllerClass = AHW_PlayerController::StaticClass();
	checkf(PlayerControllerClass, TEXT("PlayerControllerClass is not set in GameMode!"));

	DefaultPawnClass = AHW_PlayerPawn::StaticClass();
	checkf(DefaultPawnClass, TEXT("DefaultPawnClass is not set in GameMode!"));

}