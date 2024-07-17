// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Inventory/IVInventorySlotWidget.h"
#include "Components/SizeBox.h"

UIVInventorySlotWidget::UIVInventorySlotWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UIVInventorySlotWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SizeBox_Root->SetWidthOverride(50);
	SizeBox_Root->SetHeightOverride(50);
}