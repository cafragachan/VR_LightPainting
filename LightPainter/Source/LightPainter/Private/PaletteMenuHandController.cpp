// Fill out your copyright notice in the Description page of Project Settings.

#include "PaletteMenuHandController.h"
#include "WidgetComponent.h"

APaletteMenuHandController::APaletteMenuHandController()
{
	PaletteMenu = CreateDefaultSubobject<UWidgetComponent>("PaletteMenu");
	PaletteMenu->SetupAttachment(GetRootComponent());
}