// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingPicker.h"
#include "PaintingGrid.h"
#include "Saving/PainterSaveGameIndex.h"
#include "ActionButtons.h"
#include "Saving/PainterSaveGame.h"

// Sets default values
APaintingPicker::APaintingPicker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("Root"));

	PaintingGrid = CreateDefaultSubobject<UWidgetComponent>("PaintingGrid");
	PaintingGrid->SetupAttachment(GetRootComponent());

	ActionBar = CreateDefaultSubobject<UWidgetComponent>("ActionBar");
	ActionBar->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void APaintingPicker::BeginPlay()
{
	Super::BeginPlay();
	
	
	auto ActionBarWidget = Cast<UActionButtons>(ActionBar->GetUserWidgetObject());

	if (ActionBarWidget)
	{
		ActionBarWidget->SetParentPicker(this);
	}

	LoadPaintings();

}

void APaintingPicker::LoadPaintings()
{
	auto PaintingGridWidget = Cast<UPaintingGrid>(PaintingGrid->GetUserWidgetObject());
	if (!PaintingGridWidget) return;

	TArray<FString> IndexSlotNames = UPainterSaveGameIndex::Load()->GetSlotNames();

	for (int i = 0; i < IndexSlotNames.Num(); ++i)
	{
		PaintingGridWidget->AddPainting(i, IndexSlotNames[i]);
	}
}

void APaintingPicker::AddPainting()
{
	//Create Painting=SaveGame Instance and set the slotname in the SlotName internal variable
	UPainterSaveGame* PaintingSave = UPainterSaveGame::Create();
	if (PaintingSave)
	{
		PaintingSave->Save();
	}

	LoadPaintings();
}

void APaintingPicker::EnableDeleteMode()
{
	UE_LOG(LogTemp, Warning, TEXT("Delete Action Clicking----------"));

}


