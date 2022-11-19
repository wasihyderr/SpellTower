// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SDAPlayerController.generated.h"

//class letters?
/**
 * 
 */
UCLASS()
class SPELLTOWER_API ASDAPlayerController : public APlayerController
{
	GENERATED_BODY()
		ASDAPlayerController();
	UFUNCTION()
		virtual void SetupInputComponent() override;
protected:
	virtual void BeginPlay() override;
	void changeDirection(float angle);
	
};
