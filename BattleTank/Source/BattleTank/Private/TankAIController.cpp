// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
    Super:: BeginPlay();

    ATank* ControlledTank = GetControlledTank();
    if (ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AI controlled tank is: %s"), *ControlledTank->GetName());
    } else {
        UE_LOG(LogTemp, Error, TEXT("AI controlled can not be determined"));
    }

    ATank* PlayerTank = GetPlayerTank();
    if (PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("Player controlled tank is: %s"), *PlayerTank->GetName());
    } else {
        UE_LOG(LogTemp, Error, TEXT("Player controlled can not be determined"));
    }
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    Aiming();
}

void ATankAIController::Aiming()
{
    ATank* PlayerTank = GetPlayerTank();
    if (PlayerTank)
    {
        ATank* ControlledTank = GetControlledTank();
        if (ControlledTank)
        {
            ControlledTank->AimAt(PlayerTank->GetActorLocation());
        }
    } else {
        UE_LOG(LogTemp, Error, TEXT("Player tank unreachable"));
    }
}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
    APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (!PlayerPawn){ return nullptr; }

    return Cast<ATank>(PlayerPawn);
}