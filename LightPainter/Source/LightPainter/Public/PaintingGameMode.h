// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PaintingGameMode.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTPAINTER_API APaintingGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	virtual void InitGame(const FString & MapName, const FString & Options, FString & ErrorMessage) override;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = Saving)
	void Save();

	UFUNCTION(BlueprintCallable, Category = Saving)
	void Load();

private:

	//State

	FString SlotName;
};
