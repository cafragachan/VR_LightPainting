// Fill out your copyright notice in the Description page of Project Settings.

#include "Stroke.h"
#include "Components/SplineMeshComponent.h"


// Sets default values
AStroke::AStroke()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);

}

void AStroke::UpdateStroke(FVector CurrentLocation_)
{
	USplineMeshComponent* SplineMesh = CreateSplineMesh();
	
	if (SplineMesh)
	{
		FVector Start = PreviousLocation;
		FVector End = GetActorTransform().InverseTransformPosition(CurrentLocation_);
		SplineMesh->SetStartAndEnd(Start, FVector(0, 0, 0), End, FVector(0, 0, 0));

		PreviousLocation = End;
	}
}

USplineMeshComponent * AStroke::CreateSplineMesh()
{
	if (!ensure(Mesh && SplineMaterial)) return nullptr;

	USplineMeshComponent* SplineMesh = NewObject<USplineMeshComponent>(this);

	SplineMesh->SetVisibility(true);
	SplineMesh->SetMobility(EComponentMobility::Movable);
	SplineMesh->AttachToComponent(Root, FAttachmentTransformRules::SnapToTargetIncludingScale);
	SplineMesh->SetStaticMesh(Mesh);
	SplineMesh->SetMaterial(0, SplineMaterial);
	SplineMesh->RegisterComponent();

	return SplineMesh;
}