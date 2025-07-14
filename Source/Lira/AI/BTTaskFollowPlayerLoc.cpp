// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskFollowPlayerLoc.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Lira/LiraAiCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UBTTaskFollowPlayerLoc::UBTTaskFollowPlayerLoc()
{
	bNotifyTick = true;      // Enables TickTask()
	bNotifyTaskFinished = true;
	NodeName = TEXT("Follow player location task");
}

EBTNodeResult::Type UBTTaskFollowPlayerLoc::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AiController = OwnerComp.GetAIOwner();
	if (!AiController) return EBTNodeResult::Failed;
	
	ALiraAiCharacter* AiCharacter = Cast<ALiraAiCharacter>(AiController->GetPawn());
	if (!AiCharacter) return EBTNodeResult::Failed;

	if (AiCharacter->GetCharacterMovement())
	{
		//AiCharacter->GetCharacterMovement()->SetMovementMode(EMo)
	}
	
	return EBTNodeResult::InProgress;
}

void UBTTaskFollowPlayerLoc::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	AAIController* AiController = OwnerComp.GetAIOwner();
	if (!AiController) return;

	ACharacter* PC = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (!PC) return;

	AiController->MoveToActor(PC, 50.f);
}

