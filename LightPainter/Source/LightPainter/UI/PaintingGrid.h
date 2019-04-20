// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/UniformGridPanel.h"
#include "Components/HorizontalBox.h"

#include "PaintingGrid.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTPAINTER_API UPaintingGrid : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UUniformGridPanel* PaintingGrid;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UHorizontalBox* PaginationBox;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UPaintingGridCard> CardClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UDotWidget> DotWidgetBase;

public:

	UFUNCTION(BlueprintCallable, Category = "UI")
	void AddPainting(int32 CardIndex, FString PaintingName);

	void ClearPainting();

	void ClearPaginationDots();

	void AddDotWidget(bool bIsActive);

	int32 GetNumberOfSlots() const;
	
};
