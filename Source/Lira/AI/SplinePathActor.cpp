// Fill out your copyright notice in the Description page of Project Settings.


#include "SplinePathActor.h"

// Sets default values
ASplinePathActor::ASplinePathActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	SplineComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASplinePathActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASplinePathActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

