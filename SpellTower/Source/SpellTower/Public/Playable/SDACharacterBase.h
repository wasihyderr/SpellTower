// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SDACharacterBase.generated.h"
class USpringArmComponent;
class UCameraComponent;
class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class SPELLTOWER_API ASDACharacterBase : public ACharacter
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	ASDACharacterBase();
	int currentScore;
	int maxJumpHeight;
	float speed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		USpringArmComponent* springArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		UCameraComponent* cameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
		UStaticMeshComponent* staticMeshComp;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
	//	UBoxComponent* collisionBox;


	//UFUNCTION()
	//	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//// declare overlap end function
	//UFUNCTION()
	//	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);




protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void jump();
	void changeDirection(float angle);
	void updateHighScore();

public:
	//// Called every frame
	//virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
