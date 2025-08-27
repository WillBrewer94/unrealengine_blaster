// Fill out your copyright notice in the Description page of Project Settings.

#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	constexpr int PlayersNeeded = 2;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Adding Player"));
	}

	// WBREWER TODO: Maybe use AGameMode::NumPlayers here?
	if (GameState.Get()->PlayerArray.Num() >= PlayersNeeded)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Launching Match..."));
		}
		
		UWorld* World = GetWorld();
		if (World)
		{
			bUseSeamlessTravel = true;
			World->SeamlessTravel(FString("/Game/Maps/BlasterMap?listen"));
		}
		else
		{
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Failed to get world!"));
			}
		}
	}
}
