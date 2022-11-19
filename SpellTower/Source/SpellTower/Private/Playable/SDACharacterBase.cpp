
// Fill out your copyright notice in the Description page of Project Settings.


#include "Playable/SDACharacterBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"

// Sets default values
ASDACharacterBase::ASDACharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	currentScore = 0;
	speed = 1;
	maxJumpHeight = 2;

	springArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	springArmComp->SetupAttachment(RootComponent);

	cameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	cameraComp->SetupAttachment(springArmComp);

	staticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	staticMeshComp->SetupAttachment(RootComponent);
	staticMeshComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	staticMeshComp->SetCollisionProfileName(TEXT("PhysicsActor"));


}

//void ASDACharacterBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	IInteractInterface* Interface = Cast<IInteractInterface>(OtherActor);
//	if (Interface) {
//		Interface->ExecuteOnInteract(OtherActor, this);
//	}
//}



// Called when the game starts or when spawned
void ASDACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	//staticMeshComp->OnComponentBeginOverlap.AddDynamic(this, &ASDACharacterBase::OnOverlapBegin);

}


// Called to bind functionality to input
void ASDACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveRight", this, &ASDACharacterBase::changeDirection);

}

void ASDACharacterBase::changeDirection(float angle) {
	/*FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, angle);*/
	AddMovementInput(FVector(angle, 0.0f, 0.0f), 1.0f, false);
}