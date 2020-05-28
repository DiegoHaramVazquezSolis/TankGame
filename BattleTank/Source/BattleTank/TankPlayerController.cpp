// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

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

    UE_LOG(LogTemp, Error, TEXT("Tick"));
    AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank())
    { return; }

    // Get world location if linetrace throught crosshair
    //If it hits the landscape
        // Tell controlled tank to aim at this point
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}