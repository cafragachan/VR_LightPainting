// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DotWidget.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTPAINTER_API UDotWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	void SetActive(bool bIsActive_);

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	class UImage* DotImage;

protected:

	UPROPERTY(EditAnywhere)
	float DotOpacity = 0.25f;
};
