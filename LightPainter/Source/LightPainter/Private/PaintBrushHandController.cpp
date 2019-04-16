// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintBrushHandController.h"
#include "HeadMountedDisplay/Public/MotionControllerComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Stroke.h"

// Sets default values
APaintBrushHandController::APaintBrushHandController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void APaintBrushHandController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaintBrushHandController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentStroke)
	{
		CurrentStroke->UpdateStroke(GetActorLocation());
	}

}

void APaintBrushHandController::TriggerPressed()
{
	if (!ensure(StrokeBase)) return;
	CurrentStroke = GetWorld()->SpawnActor<AStroke>(StrokeBase, GetActorLocation(), GetActorRotation());
}

void APaintBrushHandController::TriggerReleased()
{
	CurrentStroke = nullptr;
}

