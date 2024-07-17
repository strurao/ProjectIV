// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/IVUserWidget.h"
#include "IVInventorySlotWidget.generated.h"
class UImage;
class USizeBox;
/**
 * 
 */
UCLASS()
class PROJECTIV_API UIVInventorySlotWidget : public UIVUserWidget
{
	GENERATED_BODY()

public:
	UIVInventorySlotWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual void NativeConstruct() override;

public:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USizeBox> SizeBox_Root;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> Image_Slot;
};
