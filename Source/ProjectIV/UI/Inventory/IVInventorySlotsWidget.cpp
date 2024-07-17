// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Inventory/IVInventorySlotsWidget.h"
#include "Components/UniformGridPanel.h"
#include "UI/Inventory/IVInventorySlotWidget.h"

UIVInventorySlotsWidget::UIVInventorySlotsWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UIVInventorySlotWidget> FindSlotWidgetClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Inventory/UI/Item/WBP_InventorySlot.WBP_InventorySlot_C'"));
	if (FindSlotWidgetClass.Succeeded())
	{
		SlotWidgetClass = FindSlotWidgetClass.Class;
	}
}

void UIVInventorySlotsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	const int X_COUNT = 10;
	const int Y_COUNT = 5;

	SlotWidgets.SetNum(X_COUNT * Y_COUNT);

	for (int32 y = 0; y < Y_COUNT; y++)
	{
		for (int32 x = 0; x < X_COUNT; x++)
		{
			int32 index = y * X_COUNT + x;

			UIVInventorySlotWidget* SlotWidget = CreateWidget<UIVInventorySlotWidget>(GetOwningPlayer(), SlotWidgetClass);
			SlotWidgets[index] = SlotWidget;
			GridPanel_Slots->AddChildToUniformGrid(SlotWidget, y, x);
		}
	}
}
