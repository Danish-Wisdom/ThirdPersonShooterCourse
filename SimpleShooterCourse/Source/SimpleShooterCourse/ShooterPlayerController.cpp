// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "ShooterCharacter.h"

AShooterPlayerController::AShooterPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (Subsystem)
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
			UE_LOG(LogTemp, Warning, TEXT("Subsystem Connected"));
		}
	}

}

void AShooterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	// This is one of the dumbest things about coding,
	// you get an error and can't figure out what's wrong and,
	// then you find out that all you needed was a closing bracket
	// or, in this case, including a header file. FML
	if (UEnhancedInputComponent* EnhancedInput = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AShooterPlayerController::HandleMovement);
		EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &AShooterPlayerController::HandleLook);
	}
	
}


void AShooterPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}




void AShooterPlayerController::HandleMovement(const FInputActionValue& Value)
{
	if (AShooterCharacter* ShooterCharacter = CastChecked<AShooterCharacter>(GetPawn()))
	{
		UE_LOG(LogTemp, Warning, TEXT("Character Connected"));
		float MoveValue = Value.Get<float>();
		
		ShooterCharacter->Move(MoveValue);
	}
}

void AShooterPlayerController::HandleLook(const FInputActionValue& Value)
{
	if (AShooterCharacter* ShooterCharacter = CastChecked<AShooterCharacter>(GetPawn()))
	{
		ShooterCharacter->AddControllerYawInput(Value.Get<float>());
	}
}





