// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "LiraAIController.generated.h"

class ALiraGameMode;
struct FAIStimulus;
class UAIPerceptionComponent;

/**
 * 
 */
UCLASS()
class LIRA_API ALiraAIController : public AAIController
{
	GENERATED_BODY()
protected:
	ALiraAIController();
public:

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void Tick(float DeltaSeconds) override;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAIPerceptionComponent* AiPerceptionComponent;

	UFUNCTION()
	virtual void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	UFUNCTION(BlueprintImplementableEvent)
	void K2_OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	//Should be enum but for now we don't even have more than 2, roam and chase
	UPROPERTY()
	bool bChaseMode = false;

	UPROPERTY()
	AActor* PlayerActor = nullptr;
	UPROPERTY()
	ALiraGameMode* GameMode = nullptr;
};
