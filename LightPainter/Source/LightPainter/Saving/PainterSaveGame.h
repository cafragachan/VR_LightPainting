// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PainterSaveGame.generated.h"


USTRUCT()
struct FStrokeState
{
	GENERATED_BODY()

	UPROPERTY()
	TSubclassOf<class AStroke> Class;

	UPROPERTY()
	TArray<FVector> ControlPoints;
};

/**
 * 
 */
UCLASS()
class LIGHTPAINTER_API UPainterSaveGame : public USaveGame
{
	GENERATED_BODY()

private:

	UPROPERTY()
	FString State;

	UPROPERTY()
	TArray<FStrokeState> Strokes;
	

public:

	static UPainterSaveGame* Load();
	static UPainterSaveGame* Create();
	bool Save();


	void SetState(FString State_);
	FString GetState();

	void SerializeFromWorld(UWorld* World);
	void DeserializeToWorld(UWorld* World);
};
