// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
    Super:: BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    Aiming();
}

void ATankAIController::Aiming()
{
    ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    if (PlayerTank)
    {
        ATank* ControlledTank = Cast<ATank>(GetPawn());
        if (ControlledTank)
        {
            ControlledTank->AimAt(PlayerTank->GetActorLocation());

            ControlledTank->Fire();
        }
    } else {
        UE_LOG(LogTemp, Error, TEXT("Player tank unreachable"));
    }
}