// Fill out your copyright notice in the Description page of Project Settings.

#include "HandController.h"
#include "HeadMountedDisplay/Public/MotionControllerComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Stroke.h"

// Sets default values
AHandController::AHandController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Controller = CreateDefaultSubobject<UMotionControllerComponent>("MotionController");
	SetRootComponent(Controller);
	
}

// Called when the game starts or when spawned
void AHandController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHandController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentStroke)
	{
		CurrentStroke->UpdateStroke(GetActorLocation());
	}

}

void AHandController::SetHandController(EControllerHand Hand)
{
	Controller->SetTrackingSource(Hand);
	Controller->SetShowDeviceModel(true);
}

void AHandController::TriggerPressed()
{
	if (!ensure(StrokeBase)) return;
	CurrentStroke = GetWorld()->SpawnActor<AStroke>(StrokeBase, GetActorLocation(), GetActorRotation());
}

void AHandController::TriggerReleased()
{
	CurrentStroke = nullptr;
}

