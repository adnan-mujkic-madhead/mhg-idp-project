// Copyright Epic Games, Inc. All Rights Reserved.

#include "LiraGameMode.h"
#include "LiraCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALiraGameMode::ALiraGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
