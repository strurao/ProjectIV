// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/IVUserWidget.h"
#include "IVInventorySlotsWidget.generated.h"
class UIVInventorySlotWidget;
class UUniformGridPanel;
class UIVInventoryEntryWidget;
class UIVItemInstance;
class UCanvasPanel;
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
	void OnInventoryEntryChanged(const FIntPoint& InItemSlotPos, TObjectPtr<UIVItemInstance> Item);
	virtual bool NativeOnDragOver(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	virtual void NativeOnDragLeave(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;

private:
	void FinishDrag();

protected:
	UPROPERTY()
	TSubclassOf<UIVInventorySlotWidget> SlotWidgetClass;

	UPROPERTY()
	TArray<TObjectPtr<UIVInventorySlotWidget>> SlotWidgets;

	UPROPERTY()
	TSubclassOf<UIVInventoryEntryWidget> EntryWidgetClass;

	UPROPERTY()
	TArray<TObjectPtr<UIVInventoryEntryWidget>> EntryWidgets;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UUniformGridPanel> GridPanel_Slots;

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCanvasPanel> CanvasPanel_Entries;

private:
	FIntPoint PrevDragOverSlotPos = FIntPoint(-1, -1);
	const int X_COUNT = 10;
	const int Y_COUNT = 5;
};
