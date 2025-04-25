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
	
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

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
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	ULiraAbilitySystemComponent* GetLiraAbilitySystemComponent() const { return LiraAbilitySystemComponent; }

	void ToggleSprint(bool bActive);
	FActiveGameplayEffectHandle SprintEffectHandle;
};

