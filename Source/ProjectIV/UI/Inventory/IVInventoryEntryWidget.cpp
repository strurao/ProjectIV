


#include "UI/Inventory/IVInventoryEntryWidget.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "UI/Inventory/IVInventorySlotsWidget.h"
#include "Item/IVItemInstance.h"
#include "UI/Item/Drag/IVDragDropOperation.h"
#include "UI/Item/Drag/IVItemDragWidget.h"

UIVInventoryEntryWidget::UIVInventoryEntryWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UIVItemDragWidget> FindDragWidgetClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Inventory/UI/Item/WBP_ItemDrag.WBP_ItemDrag_C'"));
	if (FindDragWidgetClass.Succeeded())
	{
		DragWidgetClass = FindDragWidgetClass.Class;
	}
}

void UIVInventoryEntryWidget::Init(UIVInventorySlotsWidget* InSlotsWidget, UIVItemInstance* InItemInstance, int32 InItemCount)
{
	SlotsWidget = InSlotsWidget;
	ItemInstance = InItemInstance;
	ItemCount = InItemCount;
}

void UIVInventoryEntryWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Text_Count->SetText(FText::GetEmpty());
}

void UIVInventoryEntryWidget::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);

	Image_Hover->SetRenderOpacity(1.f);
}

void UIVInventoryEntryWidget::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);

	Image_Hover->SetRenderOpacity(0.f);
}

FReply UIVInventoryEntryWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FReply Reply = Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);

	if (InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		Reply.DetectDrag(TakeWidget(), EKeys::LeftMouseButton);
	}

	const FIntPoint UnitInventorySlotSize = FIntPoint(50, 50);

	FVector2D MouseWidgetPos = SlotsWidget->GetCachedGeometry().AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
	FVector2D ItemWidgetPos = SlotsWidget->GetCachedGeometry().AbsoluteToLocal(InGeometry.LocalToAbsolute(UnitInventorySlotSize / 2.f));
	FIntPoint ItemSlotPos = FIntPoint(ItemWidgetPos.X / UnitInventorySlotSize.X, ItemWidgetPos.Y / UnitInventorySlotSize.Y);

	CachedFromSlotPos = ItemSlotPos;
	CachedDeltaWidgetPos = MouseWidgetPos - ItemWidgetPos;

	return Reply;
}

void UIVInventoryEntryWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, OUT UDragDropOperation*& OutOperation)
{
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);

	UIVItemDragWidget* DragWidget = CreateWidget<UIVItemDragWidget>(GetOwningPlayer(), DragWidgetClass);
	FVector2D EntityWidgetSize = FVector2D(1 * 50, 1 * 50);
	DragWidget->Init(EntityWidgetSize, nullptr, ItemCount);

	UIVDragDropOperation* DragDrop = NewObject<UIVDragDropOperation>();
	DragDrop->DefaultDragVisual = DragWidget;
	DragDrop->Pivot = EDragPivot::MouseDown;
	DragDrop->FromItemSlotPos = CachedFromSlotPos;
	DragDrop->ItemInstance = ItemInstance;
	DragDrop->DeltaWidgetPos = CachedDeltaWidgetPos;

	OutOperation = DragDrop;
}

void UIVInventoryEntryWidget::NativeOnDragCancelled(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	Super::NativeOnDragCancelled(InDragDropEvent, InOperation);

	RefreshWidgetOpacity(true);
}

void UIVInventoryEntryWidget::RefreshWidgetOpacity(bool bClearlyVisible)
{
	SetRenderOpacity(bClearlyVisible ? 1.f : 0.5f);
}

void UIVInventoryEntryWidget::RefreshItemCount(int32 NewItemCount)
{
	ItemCount = NewItemCount;
	Text_Count->SetText((ItemCount >= 2) ? FText::AsNumber(ItemCount) : FText::GetEmpty());
}