// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskFollowPlayerLoc.generated.h"

/**
 * 
 */
UCLASS()
class LIRA_API UBTTaskFollowPlayerLoc : public UBTTaskNode
{
	GENERATED_BODY()
	UBTTaskFollowPlayerLoc();
public:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
