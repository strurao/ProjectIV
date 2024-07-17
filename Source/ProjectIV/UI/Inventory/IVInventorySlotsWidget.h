// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/IVUserWidget.h"
#include "IVInventorySlotsWidget.generated.h"
class UIVInventorySlotWidget;
class UUniformGridPanel;
/**
 * 
 */
UCLASS()
class PROJECTIV_API UIVInventorySlotsWidget : public UIVUserWidget
{
	GENERATED_BODY()

public:
	UIVInventorySlotsWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY()
	TSubclassOf<UIVInventorySlotWidget> SlotWidgetClass;

	UPROPERTY()
	TArray<TObjectPtr<UIVInventorySlotWidget>> SlotWidgets;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UUniformGridPanel> GridPanel_Slots;
};
