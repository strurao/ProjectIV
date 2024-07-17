// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/IVGameMode.h"
#include "Subsystems/SubsystemBlueprintLibrary.h"
#include "Item/IVInventorySubsystem.h"

void AIVGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	UIVInventorySubsystem* Inventory = Cast<UIVInventorySubsystem>(USubsystemBlueprintLibrary::GetWorldSubsystem(this, UIVInventorySubsystem::StaticClass()));
	if (Inventory)
	{
		Inventory->AddDefaultItems();
	}
}
