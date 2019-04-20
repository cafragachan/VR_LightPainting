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

	Refresh();

}

void APaintingPicker::RefreshPaintingSlots()
{
	auto PaintingGridWidget = Cast<UPaintingGrid>(PaintingGrid->GetUserWidgetObject());
	if (!PaintingGridWidget) return;

	PaintingGridWidget->ClearPainting();

	TArray<FString> IndexSlotNames = UPainterSaveGameIndex::Load()->GetSlotNames();

	for (int i = 0; i < IndexSlotNames.Num(); ++i)
	{
		PaintingGridWidget->AddPainting(i, IndexSlotNames[i]);
	}

	UE_LOG(LogTemp, Warning, TEXT("Number of Pages: %i"), GetNumberOfPages());

}

void APaintingPicker::RefreshPaginationDots()
{
	auto PaintingGridWidget = Cast<UPaintingGrid>(PaintingGrid->GetUserWidgetObject());
	if (!PaintingGridWidget) return;

	PaintingGridWidget->ClearPaginationDots();

	int32 PagesNum = GetNumberOfPages();
	for (int32 i = 0; i < PagesNum; ++i)
	{
		PaintingGridWidget->AddDotWidget(i == CurrentPageNumber ? true : false);
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
	Refresh();
}

void APaintingPicker::EnableDeleteMode()
{
	auto PaintingGridWidget = Cast<UPaintingGrid>(PaintingGrid->GetUserWidgetObject());
	if (!PaintingGridWidget) return;

	PaintingGridWidget->ClearPainting();
}

int32 APaintingPicker::GetNumberOfPages() const
{
	TArray<FString> IndexSlotNames = UPainterSaveGameIndex::Load()->GetSlotNames();
	int32 NumberOfSavedSlots = IndexSlotNames.Num();

	if (!PaintingGrid) return 0;
	auto PaintingGridWidget = Cast<UPaintingGrid>(PaintingGrid->GetUserWidgetObject());

	if (!PaintingGridWidget) return 0;
	int32 NumberOfGridSlots = PaintingGridWidget->GetNumberOfSlots();
	int32 NumberOfPages = FMath::CeilToInt((float) NumberOfSavedSlots / (float) NumberOfGridSlots);

	return NumberOfPages;
}


