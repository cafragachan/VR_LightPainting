// Fill out your copyright notice in the Description page of Project Settings.

#include "ActionButtons.h"
#include "Public/Blueprint/UserWidget.h"

bool UActionButtons::Initialize()
{

	if (!Super::Initialize())
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to Initialize"));

		return false;
	}

	AddButton->OnClicked.AddDynamic(this, &UActionButtons::AddClicked);
	DeleteButton->OnClicked.AddDynamic(this, &UActionButtons::DeleteClicked);
	QuitButton->OnClicked.AddDynamic(this, &UActionButtons::QuitClicked);
	
	return true;
}

void UActionButtons::AddClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Clicked Add"));

}

void UActionButtons::DeleteClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Clicked Delete"));

}

void UActionButtons::QuitClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Clicked Quit"));
}
