// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

#define OUT

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

    ATank* ControlledTank = GetControlledTank();
    if (ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("Current controlled tank is: %s"), *ControlledTank->GetName());
    } else {
        UE_LOG(LogTemp, Error, TEXT("Current controlled can not be determined"));
    }
}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank())
    { return; }

    FVector HitLocation;
    if (GetSightRayHitLocation(HitLocation))
    {
        // Get world location if linetrace throught crosshair
        //If it hits the landscape
            // Tell controlled tank to aim at this point
    }
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
    // Find the crosshair position in pixel coordinates
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

    return true;
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}