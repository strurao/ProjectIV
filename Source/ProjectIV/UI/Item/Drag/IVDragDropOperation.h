// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "IVDragDropOperation.generated.h"
class UIVItemInstance;

/**
 * 
 */
UCLASS()
class PROJECTIV_API UIVDragDropOperation : public UDragDropOperation
{
	GENERATED_BODY()
public:
	UIVDragDropOperation(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	FIntPoint FromItemSlotPos = FIntPoint::ZeroValue;

	UPROPERTY()
	TObjectPtr<UIVItemInstance> ItemInstance;

	FVector2D DeltaWidgetPos = FVector2D::ZeroVector;
};
