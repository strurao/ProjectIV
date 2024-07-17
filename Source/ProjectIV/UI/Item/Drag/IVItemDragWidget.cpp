// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Item/Drag/IVItemDragWidget.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"

UIVItemDragWidget::UIVItemDragWidget(const FObjectInitializer& ObjectInitializer)
{
}

void UIVItemDragWidget::Init(const FVector2D& InWidgetSize, UTexture2D* InItemIcon, int32 InItemCount)
{
	SizeBox_Root->SetWidthOverride(InWidgetSize.X);
	SizeBox_Root->SetHeightOverride(InWidgetSize.Y);

	Image_Icon->SetBrushFromTexture(InItemIcon);
	Text_Count->SetText((InItemCount >= 2) ? FText::AsNumber(InItemCount) : FText::GetEmpty());
}
