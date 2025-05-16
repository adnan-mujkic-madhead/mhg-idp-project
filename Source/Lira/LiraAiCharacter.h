// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LiraCharacter.h"
#include "LiraAiCharacter.generated.h"


class ASplinePathActor;

UCLASS()
class LIRA_API ALiraAiCharacter : public ALiraCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALiraAiCharacter();

	ASplinePathActor* GetSplinePathActor() { return SplinePathRef; }

	FSoftObjectPath GetRoamingBehaviorTree() { return RoamingBehaviorTree; }

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Behavior", meta=(MetaClass="BehaviorTree"))
	ASplinePathActor* SplinePathRef;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Behavior", meta=(MetaClass="BehaviorTree"))
	FSoftObjectPath RoamingBehaviorTree;

};
