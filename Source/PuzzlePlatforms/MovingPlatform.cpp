// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"


void AMovingPlatform::Tick(float DeltaSeconds) 
{
    Super::Tick(DeltaSeconds);


    if (!CurrentLocation.Equals(EndLocation, 10.f) && bIsServer)
    {
        CurrentLocation.X += Velocity * DeltaSeconds;
        SetActorLocation(CurrentLocation);

    }
}


void AMovingPlatform::BeginPlay() 
{
    Super::BeginPlay();
    StartLocation = GetActorLocation();

	CurrentLocation = StartLocation;

    EndLocation = StartLocation + DeltaLocation;

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
