// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/Button.h"

#include "ActionButtons.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTPAINTER_API UActionButtons : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual bool Initialize() override;

	UFUNCTION(BlueprintCallable)
	void AddClicked();

	UFUNCTION(BlueprintCallable)
	void DeleteClicked();

	UFUNCTION(BlueprintCallable)
	void QuitClicked();

	void SetParentPicker(class APaintingPicker* ParentPaintingPicker_);

protected:

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UButton* DeleteButton;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UButton* AddButton;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UButton* QuitButton;

private:

	UPROPERTY()
	class APaintingPicker* ParentPaintingPicker;
	
};
