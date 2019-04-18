// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGrid.h"
#include "Components/SizeBox.h"
#include "Engine/World.h"

void UPaintingGrid::AddPainting()
{
	if (PaintingGrid)
	{
		UUserWidget * Card = CreateWidget<UUserWidget>(GetWorld(), CardClass);

		if (!Card) return;
		auto Box = Cast<USizeBox>(PaintingGrid->GetChildAt(0));

		if (!Box) return;
		Box->AddChild(Card);

		UE_LOG(LogTemp, Warning, TEXT("Box: %s"), *Box->GetName());

	}
}
