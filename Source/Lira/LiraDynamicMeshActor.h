// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DynamicMeshActor.h"
#include "LiraDynamicMeshActor.generated.h"

/**
 * 
 */
UCLASS()
class LIRA_API ALiraDynamicMeshActor : public ADynamicMeshActor
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void DestroyWall(FVector Position, float SphereRadius);
	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FVector BoxSize;

	UFUNCTION(BlueprintCallable, CallInEditor, Category= "Lira Dynamic Mesh Actor")
	void GenerateBox();
};
