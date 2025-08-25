// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	
}

void AShooterCharacter::Move(const float& MoveAxis)
{
	UE_LOG(LogTemp, Warning, TEXT("AShooterCharacter::Move"));

	FVector DeltaLocation(0.f);
	float ForwardInput = MoveAxis;;
	
	ForwardInput = ForwardInput * UGameplayStatics::GetWorldDeltaSeconds(this) * WalkSpeed;

	DeltaLocation.X = ForwardInput;
	
	//AddActorLocalOffset(DeltaLocation, true);
	AddMovementInput(GetActorForwardVector() * MoveAxis);
}

