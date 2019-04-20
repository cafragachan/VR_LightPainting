// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/WidgetComponent.h"

#include "PaintingPicker.generated.h"

UCLASS()
class LIGHTPAINTER_API APaintingPicker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APaintingPicker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Refresh() { RefreshPaintingSlots(); RefreshPaginationDots(); }

	void RefreshPaintingSlots();

	void RefreshPaginationDots();

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UWidgetComponent* PaintingGrid = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UWidgetComponent* ActionBar = nullptr;

	void AddPainting();

	void EnableDeleteMode();

	void UpdatePages(int32 Offset);

private:

	int32 GetNumberOfPages() const;

	//State
	int32 CurrentPageNumber = 0;

};