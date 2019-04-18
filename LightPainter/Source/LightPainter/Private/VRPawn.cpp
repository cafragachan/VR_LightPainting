// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPawn.h"
#include "HandControllerBase.h"
#include "Engine/World.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Saving/PainterSaveGame.h"


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
	
	if (ensure(ControllerBase))
	{
		RightController = GetWorld()->SpawnActor<AHandControllerBase>(ControllerBase);
		RightController->AttachToComponent(VRRoot, FAttachmentTransformRules::SnapToTargetIncludingScale);
		RightController->SetHandController(EControllerHand::Right);
	}

	//Create Painting=SaveGame Instance and set the slotname in the SlotName internal variable
	UPainterSaveGame* PaintingSave = UPainterSaveGame::Create();
	if (PaintingSave)
	{
		PaintingSave->Save();
		PaintingSaveSlotName = PaintingSave->GetSlotName();
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
	PlayerInputComponent->BindAction("Load", EInputEvent::IE_Pressed, this, &AVRPawn::Load);

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
	UPainterSaveGame* PaintingSave = UPainterSaveGame::Load(PaintingSaveSlotName);

	if (!PaintingSave) return;
	PaintingSave->SerializeFromWorld(GetWorld());
	PaintingSave->Save();
}

void AVRPawn::Load()
{
	UPainterSaveGame* PaintingSave = UPainterSaveGame::Load(PaintingSaveSlotName);

	if (PaintingSave)
	{
		PaintingSave->DeserializeToWorld(GetWorld());
		//UE_LOG(LogTemp, Warning, TEXT("Painting State: %s"), *PaintingSave->GetState());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Painting not found"));
	}
}


