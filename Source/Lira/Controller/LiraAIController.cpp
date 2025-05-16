// Fill out your copyright notice in the Description page of Project Settings.


#include "LiraAIController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "Engine/AssetManager.h"
#include "Lira/LiraAiCharacter.h"

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

	
}
