// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
    float RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    float Rotation = (RelativeRotation.Yaw < 0 ? 180 + (180 + RelativeRotation.Yaw) : RelativeRotation.Yaw) + RotationChange;

    FString name = GetOwner()->GetName();
    FString tank = FString("Tank_BP_C_0");
    if (name == tank && RotationChange < 0)
    {
        UE_LOG(LogTemp, Display, TEXT("%f"), Rotation);
    }

    SetRelativeRotation(FRotator(0, Rotation, 0));
}