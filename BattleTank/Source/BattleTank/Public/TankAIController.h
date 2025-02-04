// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * AI controller for the tanks
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

	void Aiming();

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float AcceptanceRadius = 3000.f;
};
