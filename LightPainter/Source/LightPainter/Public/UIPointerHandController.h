// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HandControllerBase.h"
#include "UIPointerHandController.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTPAINTER_API AUIPointerHandController : public AHandControllerBase
{
	GENERATED_BODY()


	AUIPointerHandController();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UWidgetInteractionComponent* InteractionComponent;

	void TriggerPressed() override;
	void TriggerReleased() override;


};
