// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPawn.h"
#include "HandController.h"
#include "Engine/World.h"
#include "Camera/CameraComponent.h"


// Sets default values
AVRPawn::AVRPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VRRoot = CreateDefaultSubobject<USceneComponent>("VRRoot");
	VRRoot->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>("VRCamera");
	Camera->SetupAttachment(VRRoot);
}

// Called when the game starts or when spawned
void AVRPawn::BeginPlay()
{
	Super::BeginPlay();
	
	if (ensure(ControllerBase))
	{
		RightController = GetWorld()->SpawnActor<AHandController>(ControllerBase);
		RightController->AttachToComponent(VRRoot, FAttachmentTransformRules::SnapToTargetIncludingScale);
		RightController->SetHandController(EControllerHand::Right);
	}
}

// Called every frame
void AVRPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

