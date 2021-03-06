// Fill out your copyright notice in the Description page of Project Settings.

#include "HandControllerBase.h"
#include "HeadMountedDisplay/Public/MotionControllerComponent.h"

// Sets default values
AHandControllerBase::AHandControllerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Controller = CreateDefaultSubobject<UMotionControllerComponent>("MotionController");
	SetRootComponent(Controller);

}

// Called when the game starts or when spawned
void AHandControllerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHandControllerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AHandControllerBase::SetHandController(EControllerHand Hand)
{
	Controller->SetTrackingSource(Hand);
	Controller->SetShowDeviceModel(true);
}
