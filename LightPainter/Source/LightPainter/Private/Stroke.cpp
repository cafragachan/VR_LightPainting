// Fill out your copyright notice in the Description page of Project Settings.

#include "Stroke.h"
#include "Components/SplineMeshComponent.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Engine/World.h"




// Sets default values
AStroke::AStroke()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);

	InstanceMeshPool = CreateDefaultSubobject<UInstancedStaticMeshComponent>("InstancedStaticMesh");
	InstanceMeshPool->SetupAttachment(Root);

	InstanceJointsPool = CreateDefaultSubobject<UInstancedStaticMeshComponent>("InstancedStaticJoints");
	InstanceJointsPool->SetupAttachment(Root);

}

void AStroke::UpdateStroke(FVector CurrentLocation_)
{
	ControlPoints.Add(CurrentLocation_);

	if (PreviousLocation.IsNearlyZero())
	{
		PreviousLocation = CurrentLocation_;
		InstanceJointsPool->AddInstance(GetNextJointTransform(CurrentLocation_));

		return;
	}

	InstanceMeshPool->AddInstance(GetNextMeshTransform(CurrentLocation_));
	InstanceJointsPool->AddInstance(GetNextJointTransform(CurrentLocation_));

	PreviousLocation = CurrentLocation_;
}


FTransform AStroke::GetNextMeshTransform(FVector Location_)
{
	FTransform NextTransform;
	FVector Dir = PreviousLocation - Location_;

	FQuat NextRotation = FQuat::FindBetweenNormals(FVector::ForwardVector, Dir.GetSafeNormal());

	FVector NextScale = FVector(Dir.Size(), 1, 1);

	FVector NextLocation = GetTransform().InverseTransformPosition(PreviousLocation);

	NextTransform.SetLocation(NextLocation);
	NextTransform.SetRotation(NextRotation);
	NextTransform.SetScale3D(NextScale);


	return NextTransform;
}

FTransform AStroke::GetNextJointTransform(FVector Location_)
{
	FTransform NextTransform;
	FVector NextLocation = GetTransform().InverseTransformPosition(PreviousLocation);

	NextTransform.SetLocation(NextLocation);

	return NextTransform;
}

FStrokeState AStroke::SerializeToStruct() const
{
	FStrokeState StrokeState;

	StrokeState.ControlPoints = ControlPoints;
	StrokeState.Class = GetClass();

	return StrokeState;
}

AStroke * AStroke::SpawnAndDeserializeFromStroke(UWorld* World, const FStrokeState& StrokeState_)
{
	AStroke* SavedStroke = World->SpawnActor<AStroke>(StrokeState_.Class);

	for (auto Point : StrokeState_.ControlPoints)
	{
		SavedStroke->UpdateStroke(Point);
	}

	return SavedStroke;
}