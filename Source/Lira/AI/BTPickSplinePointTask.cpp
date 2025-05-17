// Fill out your copyright notice in the Description page of Project Settings.


#include "BTPickSplinePointTask.h"

#include "AIController.h"
#include "SplinePathActor.h"
#include "BehaviorTree/BTFunctionLibrary.h"
#include "Lira/LiraAiCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTPickSplinePointTask::UBTPickSplinePointTask()
{
	NodeName = TEXT("Pick up spline point service");
}

EBTNodeResult::Type UBTPickSplinePointTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AiController = OwnerComp.GetAIOwner();
	if (!AiController) return EBTNodeResult::Type::Failed;

	ALiraAiCharacter* AiCharacter = Cast<ALiraAiCharacter>(AiController->GetPawn());
	if (!AiCharacter) return EBTNodeResult::Type::Failed;

	ASplinePathActor* SplinePathActor = AiCharacter->GetSplinePathActor();
	if (!SplinePathActor || !SplinePathActor->GetSplineComponent()) return EBTNodeResult::Type::Failed;

	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComponent) return EBTNodeResult::Type::Failed;

	bool IsForwardCounting = BlackboardComponent->GetValueAsBool(ForwardCountingIndexKey.SelectedKeyName);
	
	int32 CurrentSplineIndex = BlackboardComponent->GetValueAsInt(NextLocationIndexKey.SelectedKeyName);
	FVector Loc = SplinePathActor->GetSplineComponent()->GetLocationAtSplinePoint(CurrentSplineIndex, ESplineCoordinateSpace::World);
	BlackboardComponent->SetValueAsVector(NextLocationKey.SelectedKeyName, Loc);
	//DrawDebugCapsule(GetWorld(), Loc, 50.f, 40.f, FQuat::Identity, FColor::White, false, 10.f);
	
	int32 NumSplinePoints = SplinePathActor->GetSplineComponent()->GetNumberOfSplinePoints();
	if (IsForwardCounting)
	{
		CurrentSplineIndex++;
		if (CurrentSplineIndex >= NumSplinePoints)
		{
			CurrentSplineIndex--;
			BlackboardComponent->SetValueAsBool(ForwardCountingIndexKey.SelectedKeyName, false);
		}
	}
	else
	{
		CurrentSplineIndex--;
		if (CurrentSplineIndex <= -1)
		{
			CurrentSplineIndex++;
			BlackboardComponent->SetValueAsBool(ForwardCountingIndexKey.SelectedKeyName, true);
		}
	}
	BlackboardComponent->SetValueAsInt(NextLocationIndexKey.SelectedKeyName, CurrentSplineIndex);
	
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}

