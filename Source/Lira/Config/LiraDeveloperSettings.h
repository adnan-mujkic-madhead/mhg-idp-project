// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "LiraDeveloperSettings.generated.h"

class UGameplayEffect;
/**
 * 
 */
UCLASS(Config = Game)
class LIRA_API ULiraDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Ability System")
	TSubclassOf<UGameplayEffect> DamageEffect;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Ability System")
	TSubclassOf<UGameplayEffect> SprintEffect;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Ability System")
	TSubclassOf<UGameplayEffect> DeathEffect;
};
