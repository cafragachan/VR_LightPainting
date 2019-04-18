// Fill out your copyright notice in the Description page of Project Settings.

#include "PainterSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "Public/Templates/Casts.h"
#include "Engine/World.h"
#include "Stroke.h"
#include "EngineUtils.h"
#include "Misc/Guid.h"

UPainterSaveGame * UPainterSaveGame::Load(FString SlotName_)
{
	UPainterSaveGame* PainterLoadedGame = Cast<UPainterSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName_, 0));

	return PainterLoadedGame;
}

UPainterSaveGame * UPainterSaveGame::Create()
{
	UPainterSaveGame* PainterSaveGame = Cast<UPainterSaveGame>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
	PainterSaveGame->SlotName = FGuid::NewGuid().ToString();

	return PainterSaveGame;
}

bool UPainterSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, SlotName, 0);
}

void UPainterSaveGame::SetState(FString State_)
{
	State = State_;
}

FString UPainterSaveGame::GetState()
{
	return State;
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
