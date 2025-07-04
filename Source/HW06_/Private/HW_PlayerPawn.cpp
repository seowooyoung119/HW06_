// Fill out your copyright notice in the Description page of Project Settings.


#include "HW_PlayerPawn.h"

// Sets default values
AHW_PlayerPawn::AHW_PlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHW_PlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHW_PlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHW_PlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

