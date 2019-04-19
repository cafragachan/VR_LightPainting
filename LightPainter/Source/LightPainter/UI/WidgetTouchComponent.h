// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetInteractionComponent.h"
#include "WidgetTouchComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = UI, meta = (BlueprintSpawnableComponent))
class LIGHTPAINTER_API UWidgetTouchComponent : public UWidgetInteractionComponent
{
	GENERATED_BODY()

public:

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction) override;
	

private:
	// State
	bool bIsClicked = false;

};
