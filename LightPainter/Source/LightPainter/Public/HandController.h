// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HandController.generated.h"

UCLASS()
class LIGHTPAINTER_API AHandController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHandController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AStroke> StrokeBase;

	//AStroke* Stroke = nullptr;

	class UMotionControllerComponent* Controller = nullptr;

	//State
	AStroke* CurrentStroke = nullptr;

public:

	void SetHandController(EControllerHand Hand);

	void TriggerPressed();
	void TriggerReleased();

};
