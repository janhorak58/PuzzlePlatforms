// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"


void AMovingPlatform::Tick(float DeltaSeconds) 
{
    Super::Tick(DeltaSeconds);


    if (!CurrentLocation.Equals(GlobalEndLocation, 10.f) && bIsServer)
    {

        CurrentLocation += TargetVector * DeltaSeconds * Velocity;
        SetActorLocation(CurrentLocation);

    }
}


void AMovingPlatform::BeginPlay() 
{
    Super::BeginPlay();
    StartLocation = GetActorLocation();

	CurrentLocation = StartLocation;
    GlobalEndLocation = GetTransform().TransformPosition(EndLocation);
    TargetVector = (GlobalEndLocation- StartLocation).GetSafeNormal();

    bIsServer = HasAuthority();

    if (bIsServer)
    {
        SetReplicates(true);
        SetReplicateMovement(true);
    }
   
}

AMovingPlatform::AMovingPlatform() 
{
    PrimaryActorTick.bCanEverTick = true;
    SetMobility(EComponentMobility::Movable);
}
