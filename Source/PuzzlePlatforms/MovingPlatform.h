// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AMovingPlatform();
	virtual void Tick( float DeltaSeconds ) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	float Velocity = 20.f;

	FVector StartLocation;

	FVector CurrentLocation;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector EndLocation;

	FVector GlobalEndLocation;

	FVector TargetVector;

	bool bIsServer;


	
};
