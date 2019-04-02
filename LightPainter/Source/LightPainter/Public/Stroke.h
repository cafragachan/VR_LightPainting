// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Saving/PainterSaveGame.h"
#include "Stroke.generated.h"

class UInstancedStaticMeshComponent;

UCLASS()
class LIGHTPAINTER_API AStroke : public AActor
{
	GENERATED_BODY()

private:

	UPROPERTY()
	USceneComponent* Root = nullptr;

	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* Mesh;

	//UPROPERTY(EditDefaultsOnly)
	//class UMaterialInterface* SplineMaterial;

	UPROPERTY(VisibleAnywhere)
	class UInstancedStaticMeshComponent* InstanceMeshPool;

	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* InstanceJointsPool;

	FTransform GetNextMeshTransform(FVector Location_);
	FTransform GetNextJointTransform(FVector Location_);

	//State
	FVector PreviousLocation;
	TArray<FVector> ControlPoints;

	
public:	
	// Sets default values for this actor's properties
	AStroke();

	void UpdateStroke(FVector CurrentLocation_);

	FStrokeState SerializeToStruct() const;
	static AStroke* SpawnAndDeserializeFromStroke(UWorld* World, const FStrokeState& StrokeState_);

};
