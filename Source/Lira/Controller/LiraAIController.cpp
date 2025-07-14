// Fill out your copyright notice in the Description page of Project Settings.


#include "LiraAIController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "Engine/AssetManager.h"
#include "Kismet/GameplayStatics.h"
#include "Lira/LiraAiCharacter.h"
#include "Lira/LiraGameMode.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AIPerceptionSystem.h"

ALiraAIController::ALiraAIController()
{

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	AiPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AiPerceptionComponent"));
}

void ALiraAIController::BeginPlay()
{
	Super::BeginPlay();

	if (ALiraAiCharacter* AiCharacter = Cast<ALiraAiCharacter>(GetCharacter()))
	{
		AiCharacter->GetRoamingBehaviorTree().LoadAsync(FLoadSoftObjectPathAsyncDelegate::CreateLambda([this](const FSoftObjectPath& ObjectPath, UObject* Object)
		{
			RunBehaviorTree(Cast<UBehaviorTree>(Object));
		}));
	}

	AiPerceptionComponent->OnTargetPerceptionUpdated.AddUniqueDynamic(this, &ALiraAIController::OnTargetPerceptionUpdated);

	PlayerActor = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	GameMode = Cast<ALiraGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

void ALiraAIController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	AiPerceptionComponent->OnTargetPerceptionUpdated.RemoveDynamic(this, &ALiraAIController::OnTargetPerceptionUpdated);
}

void ALiraAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (bChaseMode && PlayerActor && GetPawn())
	{
		if (FVector::DistSquared(GetPawn()->GetActorLocation(), PlayerActor->GetActorLocation()) >= 2500.f)
		{
			GameMode->CatchPlayer(GetPawn());
		}
	}
}

void ALiraAIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (!Actor || UAIPerceptionSystem::GetSenseClassForStimulus(GetWorld(), Stimulus).Get() != UAISense_Sight::StaticClass())
	{
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("Sensed, %s"), *Actor->GetActorNameOrLabel());
	if (ALiraAiCharacter* AiCharacter = Cast<ALiraAiCharacter>(GetCharacter()))
	{
		AiCharacter->GetChasingBehaviorTree().LoadAsync(FLoadSoftObjectPathAsyncDelegate::CreateLambda([this](const FSoftObjectPath& ObjectPath, UObject* Object)
		{
			RunBehaviorTree(Cast<UBehaviorTree>(Object));
			bChaseMode = true;
		}));
	}
	K2_OnTargetPerceptionUpdated(Actor, Stimulus);
}
