// Fill out your copyright notice in the Description page of Project Settings.

#include "UIPointerHandController.h"
#include "Components/WidgetInteractionComponent.h"
#include "Classes/InputCoreTypes.h"

AUIPointerHandController::AUIPointerHandController()
{
	InteractionComponent = CreateDefaultSubobject<UWidgetInteractionComponent>("Widget Interaction Component");
	InteractionComponent->SetupAttachment(GetRootComponent());
}

void AUIPointerHandController::TriggerPressed()
{
	InteractionComponent->PressPointerKey(EKeys::LeftMouseButton);
	UE_LOG(LogTemp, Warning, TEXT("Hello CPP"));

}

void AUIPointerHandController::TriggerReleased()
{
	InteractionComponent->ReleasePointerKey(EKeys::LeftMouseButton);
	UE_LOG(LogTemp, Warning, TEXT("Hello CPP"));

}
