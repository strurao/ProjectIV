// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "IVInventorySubsystem.generated.h"
class UIVItemInstance;
/**
 * 
 */
UCLASS()
class PROJECTIV_API UIVInventorySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	/** Implement this for initialization of instances of the system */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Implement this for deinitialization of instances of the system */
	virtual void Deinitialize() override;

	// TEMP
	void AddDefaultItems();

	const TArray<TObjectPtr<UIVItemInstance>>& GetItems() { return Items; }

protected:
	UPROPERTY()
	TArray<TObjectPtr<UIVItemInstance>> Items;
};
