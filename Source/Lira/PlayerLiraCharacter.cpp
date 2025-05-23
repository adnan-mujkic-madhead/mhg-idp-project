// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerLiraCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMaterialLibrary.h"


APlayerLiraCharacter::APlayerLiraCharacter() {

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

}

void APlayerLiraCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (MinimapMpc)
	{
		UKismetMaterialLibrary::SetVectorParameterValue(GetWorld(), MinimapMpc, FName("PlayerPos"), FLinearColor(GetActorLocation()));
	}
}
