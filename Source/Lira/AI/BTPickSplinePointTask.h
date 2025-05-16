// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTPickSplinePointTask.generated.h"

/**
 * 
 */
UCLASS()
class LIRA_API UBTPickSplinePointTask : public UBTTaskNode
{
	GENERATED_BODY()

	UBTPickSplinePointTask();
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	FBlackboardKeySelector NextLocationKey;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	FBlackboardKeySelector NextLocationIndexKey;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
