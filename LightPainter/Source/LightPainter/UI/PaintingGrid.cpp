// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGrid.h"
#include "Components/SizeBox.h"
#include "Engine/World.h"
#include "PaintingGridCard.h"
#include "DotWidget.h"
#include "Components/HorizontalBoxSlot.h"

void UPaintingGrid::AddPainting(int32 CardIndex, FString PaintingName)
{
	if (PaintingGrid)
	{
		UPaintingGridCard * Card = CreateWidget<UPaintingGridCard>(GetWorld(), CardClass);

		if (!Card) return;
		Card->SetPaintingName(PaintingName);
		auto Box = Cast<USizeBox>(PaintingGrid->GetChildAt(CardIndex));

		if (!Box) return;
		Box->AddChild(Card);
	}
}

void UPaintingGrid::ClearPainting()
{
	if (PaintingGrid)
	{
		auto GridCount = PaintingGrid->GetChildrenCount();

		for (int i = 0; i < GridCount; ++i)
		{
			Cast<UPanelWidget>(PaintingGrid->GetChildAt(i))->ClearChildren();
		}

	}
}

void UPaintingGrid::AddDotWidget(bool bIsActive)
{
	if (PaginationBox)
	{
		if (!ensure(DotWidgetBase)) return;
		UDotWidget* PaginationDot = CreateWidget<UDotWidget>(this, DotWidgetBase);

		if (!PaginationDot) return;
		PaginationDot->SetActive(bIsActive);
		UHorizontalBoxSlot* BoxSlot = PaginationBox->AddChildToHorizontalBox(PaginationDot);
		BoxSlot->SetPadding(FMargin(8.f, 0, 0, 0));
	}
}
