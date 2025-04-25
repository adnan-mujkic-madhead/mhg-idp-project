// Fill out your copyright notice in the Description page of Project Settings.


#include "LiraAttributeSet.h"

#include "Net/UnrealNetwork.h"

ULiraAttributeSet::ULiraAttributeSet():
	Health(100.f),
	MaxHealth(100.f),
	MovementSpeed(600.f),
	DamageMultiplier(1.f)
{}

void ULiraAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(ULiraAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULiraAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULiraAttributeSet, MovementSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULiraAttributeSet, DamageMultiplier, COND_None, REPNOTIFY_Always);
}

void ULiraAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULiraAttributeSet, Health, OldHealth);
}

void ULiraAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULiraAttributeSet, MaxHealth, OldMaxHealth);
}

void ULiraAttributeSet::OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULiraAttributeSet, MovementSpeed, OldMovementSpeed);
}

void ULiraAttributeSet::OnRep_DamageMultiplier(const FGameplayAttributeData& OldDamageMultiplier)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULiraAttributeSet, DamageMultiplier, OldDamageMultiplier);
}
