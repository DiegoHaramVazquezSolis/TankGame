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

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}