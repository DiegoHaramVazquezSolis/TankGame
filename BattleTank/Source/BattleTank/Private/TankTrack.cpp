// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetTankThrottle(float Throttle)
{
    FVector ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
    FVector ForceLocation = GetComponentLocation();
    UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    /* TArray<USceneComponent*> childs;
    FString name = GetOwner()->GetName();
    FString tank = FString("Tank_BP_C_0");
    if (name == tank)
    {
        GetOwner()->GetRootComponent()->GetChildrenComponents(false, childs);
        for (USceneComponent* child : childs)
        {
            if (child->GetName().Contains(TEXT("Track"), ESearchCase::IgnoreCase, ESearchDir::FromEnd))
            {
                UE_LOG(LogTemp, Display, TEXT("Children: %s"), *child->GetName());
            }
        }
    } */
    UE_LOG(LogTemp, Display, TEXT("Children: %s"), *ForceLocation.ToString());
    TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}