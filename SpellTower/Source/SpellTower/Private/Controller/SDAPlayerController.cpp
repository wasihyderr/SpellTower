// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/SDAPlayerController.h"

#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "Playable/SDACharacterBase.h"

ASDAPlayerController::ASDAPlayerController() {

}

void ASDAPlayerController::BeginPlay()
{
	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);
}

void ASDAPlayerController::SetupInputComponent()
{
}

void ASDAPlayerController::changeDirection(float angle)
{
}
