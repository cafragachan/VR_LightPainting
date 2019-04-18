// Fill out your copyright notice in the Description page of Project Settings.

#include "PainterSaveGameIndex.h"
#include "Kismet/GameplayStatics.h"
#include "PainterSaveGame.h"


const FString UPainterSaveGameIndex::SLOT_NAME = "PaintingIndex";

UPainterSaveGameIndex* UPainterSaveGameIndex::Load()
{
	UPainterSaveGameIndex* LoadIndex = Cast<UPainterSaveGameIndex>(UGameplayStatics::LoadGameFromSlot(SLOT_NAME, 0));

	if (!LoadIndex)
	{
		LoadIndex = Cast<UPainterSaveGameIndex>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
		LoadIndex->Save();
	}

	return LoadIndex;
}

bool UPainterSaveGameIndex::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, SLOT_NAME, 0);
}

void UPainterSaveGameIndex::AddSaveGame(UPainterSaveGame * SaveGame)
{
	SlotNames.Add(SaveGame->GetSlotName());
}

