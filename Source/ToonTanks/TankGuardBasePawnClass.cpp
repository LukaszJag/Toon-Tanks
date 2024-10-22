// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGuardBasePawnClass.h"
#include "Perception/PawnSensingComponent.h"
#include "DrawDebugHelpers.h"

ATankGuardBasePawnClass::ATankGuardBasePawnClass()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));

	PawnSensingComp->OnSeePawn.AddDynamic(this, &ATankGuardBasePawnClass::OnPawnSeen);

}

// Called when the game starts or when spawned
void ATankGuardBasePawnClass::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATankGuardBasePawnClass::OnPawnSeen(APawn *SeenPawn)
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
void ATankGuardBasePawnClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATankGuardBasePawnClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
