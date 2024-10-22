// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGuard.h"
#include "Perception/PawnSensingComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
ATankGuard::ATankGuard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));

	PawnSensingComp->OnSeePawn.AddDynamic(this, &ATankGuard::OnPawnSeen);

}

// Called when the game starts or when spawned
void ATankGuard::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATankGuard::OnPawnSeen(APawn *SeenPawn)
{
		UE_LOG(LogTemp, Warning, TEXT("Hello"));
	if (SeenPawn == nullptr)
	{
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("On see trigger"));

	DrawDebugSphere(GetWorld(), SeenPawn->GetActorLocation(), 32.0f, 12, FColor::Yellow, false, 10.0f);
}

// Called every frame
void ATankGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATankGuard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

