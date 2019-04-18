// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPawn.h"
#include "HandControllerBase.h"
#include "Engine/World.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Saving/PainterSaveGame.h"
#include "PaintingGameMode.h"


AVRPawn::AVRPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VRRoot = CreateDefaultSubobject<USceneComponent>("VRRoot");
	VRRoot->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>("VRCamera");
	Camera->SetupAttachment(VRRoot);
}


void AVRPawn::BeginPlay()
{
	Super::BeginPlay();
	
	if (ensure(RightControllerBase))
	{
		RightController = GetWorld()->SpawnActor<AHandControllerBase>(RightControllerBase);
		RightController->AttachToComponent(VRRoot, FAttachmentTransformRules::SnapToTargetIncludingScale);
		RightController->SetHandController(EControllerHand::Right);
	}
	if (ensure(LeftControllerBase))
	{
		LeftController = GetWorld()->SpawnActor<AHandControllerBase>(LeftControllerBase);
		LeftController->AttachToComponent(VRRoot, FAttachmentTransformRules::SnapToTargetIncludingScale);
		LeftController->SetHandController(EControllerHand::Left);
	}
}


void AVRPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Paint", EInputEvent::IE_Pressed, this, &AVRPawn::RightTriggerPressed);
	PlayerInputComponent->BindAction("Paint", EInputEvent::IE_Released, this, &AVRPawn::RightTriggerReleased);
	PlayerInputComponent->BindAction("Save", EInputEvent::IE_Pressed, this, &AVRPawn::Save);
}


void AVRPawn::RightTriggerPressed()
{
	RightController->TriggerPressed();
}

void AVRPawn::RightTriggerReleased()
{
	RightController->TriggerReleased();
}

void AVRPawn::Save()
{
	auto MyGameMode = Cast<APaintingGameMode>(GetWorld()->GetAuthGameMode());
	MyGameMode->Save();

}





