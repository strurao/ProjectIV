

#pragma once

#include "CoreMinimal.h"
#include "UI/IVUserWidget.h"
#include "IVInventoryEntryWidget.generated.h"

class USizeBox;
class UTextBlock;
class UImage;
class UIVInventorySlotsWidget;
class UIVItemInstance;
class UIVItemDragWidget;

/**
 *
 */
UCLASS()
class PROJECTIV_API UIVInventoryEntryWidget : public UIVUserWidget
{
	GENERATED_BODY()

	public:
		UIVInventoryEntryWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());


public:
	void Init(UIVInventorySlotsWidget* InSlotsWidget, UIVItemInstance* InItemInstance, int32 InItemCount);

protected:
	virtual void NativeConstruct() override;
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;
	virtual void NativeOnDragCancelled(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;

	void RefreshWidgetOpacity(bool bClearlyVisible);
	void RefreshItemCount(int32 NewItemCount);

private:
	FIntPoint CachedFromSlotPos = FIntPoint::ZeroValue;
	FVector2D CachedDeltaWidgetPos = FVector2D::ZeroVector;
	int32 ItemCount = 0;

protected:
	UPROPERTY()
	TObjectPtr<UIVInventorySlotsWidget> SlotsWidget;

	UPROPERTY()
	TObjectPtr<UIVItemInstance> ItemInstance;

	UPROPERTY()
	TSubclassOf<UIVItemDragWidget> DragWidgetClass;

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USizeBox> SizeBox_Root;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Text_Count;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> Image_Icon;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> Image_Hover;
};
