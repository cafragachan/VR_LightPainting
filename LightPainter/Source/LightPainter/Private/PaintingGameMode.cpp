// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Saving/PainterSaveGame.h"
#include "Kismet/StereoLayerFunctionLibrary.h"
#include "Engine/World.h"


void APaintingGameMode::InitGame(const FString & MapName, const FString & Options, FString & ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	SlotName = UGameplayStatics::ParseOption(Options, "SlotName");

	UE_LOG(LogTemp, Warning, TEXT("Slot Name:"));
	UE_LOG(LogTemp, Warning, TEXT("%s"), *SlotName);

}

void APaintingGameMode::BeginPlay()
{
	Super::BeginPlay();

	Load();
	UStereoLayerFunctionLibrary::HideSplashScreen(); //IMPORTANT since we called show splash scene we have to hide it.

}

void APaintingGameMode::Save()
{
	UPainterSaveGame* PaintingSave = UPainterSaveGame::Load(SlotName);

	if (!PaintingSave) return;
	PaintingSave->SerializeFromWorld(GetWorld());
	PaintingSave->Save();

	UGameplayStatics::OpenLevel(GetWorld(), FName("MainMenu"));

}

void APaintingGameMode::Load()
{
	UPainterSaveGame* PaintingSave = UPainterSaveGame::Load(SlotName);

	if (PaintingSave)
	{
		PaintingSave->DeserializeToWorld(GetWorld());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Painting not found"));
	}
}
