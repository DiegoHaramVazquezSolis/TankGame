// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Tank.h"

#define OUT

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
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
        GetControlledTank()->AimAt(HitLocation);
    }
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
    // Find the crosshair position in pixel coordinates
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
    FVector LookDirection;
    if (GetLookDirection(ScreenLocation, LookDirection))
    {
        GetLookVectorHitLocation(LookDirection, OutHitLocation);
    } else {
        UE_LOG(LogTemp, Warning, TEXT("unable to determine LookDirection value"));
    }

    return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const
{
    FVector CameraWorldLocation;

    return DeprojectScreenPositionToWorld(
            ScreenLocation.X,
            ScreenLocation.Y,
            CameraWorldLocation,
            LookDirection
        );
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &OutHitLocation) const
{
    FHitResult HitResult;
    FVector StartLocation = PlayerCameraManager->GetCameraLocation();
    FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);
    if (GetWorld()->LineTraceSingleByChannel(
            HitResult,
            StartLocation,
            EndLocation,
            ECollisionChannel::ECC_Visibility
        )
    )
    {
        OutHitLocation = HitResult.Location;
        return true;
    }

    OutHitLocation = FVector(0.f);
    return false;
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}