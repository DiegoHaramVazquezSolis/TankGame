// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetTankThrottle(float Throttle)
{
    FVector ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
    FVector ForceLocation = GetComponentLocation();
    UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

    TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}