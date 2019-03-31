// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Stroke.generated.h"

UCLASS()
class LIGHTPAINTER_API AStroke : public AActor
{
	GENERATED_BODY()

private:

	UPROPERTY()
	USceneComponent* Root = nullptr;

	UPROPERTY(EditDefaultsOnly)
	class UStaticMesh* Mesh;

	UPROPERTY(EditDefaultsOnly)
	class UMaterialInterface* SplineMaterial;

	TArray<class USplineMeshComponent*>SplineMeshPool;

	USplineMeshComponent* CreateSplineMesh();

	FVector PreviousLocation;
	
public:	
	// Sets default values for this actor's properties
	AStroke();

	void UpdateStroke(FVector CurrentLocation_);

};
