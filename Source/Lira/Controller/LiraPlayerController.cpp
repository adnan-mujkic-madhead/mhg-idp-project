// Fill out your copyright notice in the Description page of Project Settings.


#include "LiraPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Lira/LiraCharacter.h"

void ALiraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ALiraPlayerController::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ALiraPlayerController::StopJump);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ALiraPlayerController::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ALiraPlayerController::Look);

		EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Started, this, &ALiraPlayerController::Crouch);
		EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Completed, this, &ALiraPlayerController::StopCrouch);
		
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &ALiraPlayerController::Sprint);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &ALiraPlayerController::StopSprint);
		
		EnhancedInputComponent->BindAction(StartAimAction, ETriggerEvent::Triggered, this, &ALiraPlayerController::StartAim);
		EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &ALiraPlayerController::Fire);
	}

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void ALiraPlayerController::Move(const FInputActionValue& Value)
{
	if (ALiraCharacter* LiraChar = Cast<ALiraCharacter>(GetPawn()))
	{
		LiraChar->Move(Value.Get<FVector2D>());
	}
}

void ALiraPlayerController::Look(const FInputActionValue& Value)
{
	if (ALiraCharacter* LiraChar = Cast<ALiraCharacter>(GetPawn()))
	{
		LiraChar->Look(Value.Get<FVector2D>());
	}
}

void ALiraPlayerController::Jump(const FInputActionValue& Value)
{
	if (ALiraCharacter* LiraChar = Cast<ALiraCharacter>(GetPawn()))
	{
		LiraChar->Jump();
	}
}

void ALiraPlayerController::StopJump(const FInputActionValue& Value)
{
	if (ALiraCharacter* LiraChar = Cast<ALiraCharacter>(GetPawn()))
	{
		LiraChar->StopJumping();
	}
}

void ALiraPlayerController::Crouch(const FInputActionValue& Value)
{
	if (ALiraCharacter* LiraChar = Cast<ALiraCharacter>(GetPawn()))
	{
		LiraChar->Crouch();
	}
}

void ALiraPlayerController::StopCrouch(const FInputActionValue& Value)
{
	if (ALiraCharacter* LiraChar = Cast<ALiraCharacter>(GetPawn()))
	{
		LiraChar->UnCrouch();
	}
}

void ALiraPlayerController::Sprint(const FInputActionValue& Value)
{
	if (ALiraCharacter* LiraChar = Cast<ALiraCharacter>(GetPawn()))
	{
		LiraChar->ToggleSprint(true);
	}
}

void ALiraPlayerController::StopSprint(const FInputActionValue& Value)
{
	if (ALiraCharacter* LiraChar = Cast<ALiraCharacter>(GetPawn()))
	{
		LiraChar->ToggleSprint(false);
	}
}

void ALiraPlayerController::StartAim(const FInputActionValue& Value)
{
}

void ALiraPlayerController::Fire(const FInputActionValue& Value)
{
}
