// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "AbilitySystem/LiraAbilitySystemComponent.h"
#include "LiraCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class ALiraCharacter : public ACharacter
{
	GENERATED_BODY()


	virtual void Tick(float DeltaSeconds) override;
public:
	ALiraCharacter();

	/** Called for movement input */
	void Move(const FVector2D& MovementVector);

	/** Called for looking input */
	void Look(const FVector2D& LookAxisVector);


	UPROPERTY()
	ULiraAbilitySystemComponent* LiraAbilitySystemComponent;
	
	UPROPERTY()
	ULiraAttributeSet* LiraAttributeSet;

public:

	UFUNCTION(BlueprintCallable, BlueprintPure)
	ULiraAbilitySystemComponent* GetLiraAbilitySystemComponent() const { return LiraAbilitySystemComponent; }

	void ToggleSprint(bool bActive);
	FActiveGameplayEffectHandle SprintEffectHandle;
};

