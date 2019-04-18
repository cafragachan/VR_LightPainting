// Fill out your copyright notice in the Description page of Project Settings.

#include "PainterSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "Public/Templates/Casts.h"
#include "Engine/World.h"
#include "Stroke.h"
#include "EngineUtils.h"
#include "Misc/Guid.h"
#include "PainterSaveGameIndex.h"



UPainterSaveGame * UPainterSaveGame::Create()
{
	UPainterSaveGame* PainterSaveGame = Cast<UPainterSaveGame>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
	PainterSaveGame->SlotName = FGuid::NewGuid().ToString();

	if (!PainterSaveGame->Save()) return nullptr;

	UPainterSaveGameIndex* Index = UPainterSaveGameIndex::Load();
	Index->AddSaveGame(PainterSaveGame);
	Index->Save();

	return PainterSaveGame;
}



bool UPainterSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, SlotName, 0);
}



UPainterSaveGame * UPainterSaveGame::Load(FString SlotName_)
{
	UPainterSaveGame* PainterLoadedGame = Cast<UPainterSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName_, 0));

	return PainterLoadedGame;
}


void UPainterSaveGame::SerializeFromWorld(UWorld * World)
{
	Strokes.Empty();

	for (TActorIterator<AStroke> StrokeItr(World); StrokeItr; ++StrokeItr)
	{
		Strokes.Add(StrokeItr->SerializeToStruct());
	}
}

void UPainterSaveGame::DeserializeToWorld(UWorld * World)
{
	for (TActorIterator<AStroke> StrokeItr(World); StrokeItr; ++StrokeItr)
	{
		StrokeItr->Destroy();
	}

	for (FStrokeState Stroke : Strokes)
	{
		AStroke::SpawnAndDeserializeFromStroke(World, Stroke);
	}
}
