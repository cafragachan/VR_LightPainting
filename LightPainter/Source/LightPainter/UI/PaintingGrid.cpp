// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGrid.h"
#include "Components/SizeBox.h"
#include "Engine/World.h"
#include "PaintingGridCard.h"

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
