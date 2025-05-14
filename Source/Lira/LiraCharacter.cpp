// Copyright Epic Games, Inc. All Rights Reserved.

#include "LiraCharacter.h"

#include "AbilitySystem/LiraAttributeSet.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Config/LiraDeveloperSettings.h"
#include "Components/CapsuleComponent.h"


DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ALiraCharacter

void ALiraCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (UCharacterMovementComponent* MovementComponent = Cast<UCharacterMovementComponent>(GetMovementComponent()))
	{
		if (LiraAbilitySystemComponent)
		{
			MovementComponent->MaxWalkSpeed = LiraAbilitySystemComponent->GetNumericAttribute(ULiraAttributeSet::GetMovementSpeedAttribute());
		}
	}
}

ALiraCharacter::ALiraCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	LiraAbilitySystemComponent = CreateDefaultSubobject<ULiraAbilitySystemComponent>(TEXT("LiraAbilitySystemComponent"));
	LiraAttributeSet = CreateDefaultSubobject<ULiraAttributeSet>(FName("LiraAttributeSet"));
}

void ALiraCharacter::Move(const FVector2D& MovementVector)
{
	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ALiraCharacter::Look(const FVector2D& LookAxisVector)
{
	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ALiraCharacter::ToggleSprint(bool bActive)
{
	if (LiraAbilitySystemComponent)
	{
		if (bActive)
		{
			SprintEffectHandle = LiraAbilitySystemComponent->BP_ApplyGameplayEffectToSelf(GetDefault<ULiraDeveloperSettings>()->SprintEffect, 1.0f, LiraAbilitySystemComponent->MakeEffectContext());
		}
		else
		{
			LiraAbilitySystemComponent->RemoveActiveGameplayEffect(SprintEffectHandle);
		}
	}
}
