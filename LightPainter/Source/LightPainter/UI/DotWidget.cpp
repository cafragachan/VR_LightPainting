// Fill out your copyright notice in the Description page of Project Settings.

#include "DotWidget.h"
#include "Components/Image.h"

void UDotWidget::SetActive(bool bIsActive)
{
	DotImage->SetOpacity(bIsActive ? 1.f : DotOpacity);
}
