// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "GameFramework/Actor.h"
#include "SplinePathActor.generated.h"

UCLASS()
class LIRA_API ASplinePathActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASplinePathActor();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SplinePathActor")
	USplineComponent* GetSplineComponent() { return SplineComponent; }

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	USplineComponent* SplineComponent;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
