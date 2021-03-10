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

	FVector EndLocation;

	UPROPERTY(EditAnywhere)
	FVector DeltaLocation = FVector(800, 0, 0);

	bool bIsServer;


	
};
