// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
    UE_LOG(LogTemp, Warning, TEXT("%s vectoring to: %s"), *GetOwner()->GetName(), *MoveVelocity.ToString());
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
    LeftTrack->SetTankThrottle(Throw);
    RightTrack->SetTankThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
    LeftTrack->SetTankThrottle(Throw);
    RightTrack->SetTankThrottle(-Throw);
}