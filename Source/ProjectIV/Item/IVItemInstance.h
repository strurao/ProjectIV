// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Share/IVDefine.h"
#include "UObject/NoExportTypes.h"
#include "IVItemInstance.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class PROJECTIV_API UIVItemInstance : public UObject
{
	GENERATED_BODY()

public:
	UIVItemInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	void Init(int32 InItemID);

public:
	UPROPERTY()
	int32 ItemID = 0;

	UPROPERTY()
	EItemRarity ItemRarity = EItemRarity::Junk;
};
