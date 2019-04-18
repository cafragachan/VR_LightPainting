// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "VRPawn.generated.h"

UCLASS()
class LIGHTPAINTER_API AVRPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AVRPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	UPROPERTY(VisibleAnyWhere)
	USceneComponent* VRRoot = nullptr;

	UPROPERTY(EditDefaultsOnly)
	class UCameraComponent* Camera = nullptr;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AHandControllerBase> RightControllerBase = nullptr;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AHandControllerBase> LeftControllerBase = nullptr;

	UPROPERTY(VisibleAnyWhere)
	class AHandControllerBase* RightController = nullptr;

	UPROPERTY(VisibleAnyWhere)
	class AHandControllerBase* LeftController = nullptr;

	FString PaintingSaveSlotName;

	void RightTriggerPressed();
	void RightTriggerReleased();
	void Save();

};
