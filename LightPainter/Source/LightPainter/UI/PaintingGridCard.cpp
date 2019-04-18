// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGridCard.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/StereoLayerFunctionLibrary.h"

void UPaintingGridCard::SetPaintingName(FString PaintingName_)
{
	PaintingSlotName = PaintingName_;

	if (!SlotName) return;
	SlotName->SetText(FText::FromString(PaintingSlotName));

	if (!CardButton) return;
	CardButton->OnClicked.AddDynamic(this, &UPaintingGridCard::OnCardButtonClicked);
}

void UPaintingGridCard::OnCardButtonClicked()
{
	UStereoLayerFunctionLibrary::ShowSplashScreen(); //NO NEED for now but use it if ever find lag between opening scenes.

	UGameplayStatics::OpenLevel(GetWorld(), FName("MainMap"), true, "SlotName=" + PaintingSlotName);

}
