// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "TankGuardBasePawnClass.generated.h"

class UPawnSensingComponent;

UCLASS()
class TOONTANKS_API ATankGuardBasePawnClass : public ABasePawn
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	ATankGuardBasePawnClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPawnSensingComponent* PawnSensingComp;

	UFUNCTION()
	void OnPawnSeen(APawn* SeenPawn);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};


