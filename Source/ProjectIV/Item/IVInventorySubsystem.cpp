// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/IVInventorySubsystem.h"
#include "Item/IVItemInstance.h"

void UIVInventorySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UIVInventorySubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UIVInventorySubsystem::AddDefaultItems()
{
	TObjectPtr<UIVItemInstance> Item = NewObject<UIVItemInstance>();
	Item->Init(100);

	Items.Add(Item);
}