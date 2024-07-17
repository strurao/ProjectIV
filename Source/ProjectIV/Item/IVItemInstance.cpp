// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/IVItemInstance.h"

UIVItemInstance::UIVItemInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UIVItemInstance::Init(int32 InItemID)
{
	if (InItemID <= 0)
		return;

	ItemID = InItemID;
	ItemRarity = EItemRarity::Common;
}