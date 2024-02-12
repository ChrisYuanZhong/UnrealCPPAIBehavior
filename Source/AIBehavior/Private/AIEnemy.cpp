// Fill out your copyright notice in the Description page of Project Settings.


#include "AIEnemy.h"
#include <States/WanderState.h>
#include <GameFramework/CharacterMovementComponent.h>

// Sets default values
AAIEnemy::AAIEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAIEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentState = NewObject<UWanderState>();
}

// Called every frame
void AAIEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentState->Update(this, DeltaTime);
}

// Called to bind functionality to input
void AAIEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAIEnemy::OnMoveCompleted()
{
	// Wait for 2 seconds
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AAIEnemy::SetNotMoving, 2.0f, false);
}

void AAIEnemy::SetNotMoving()
{
	bIsMoving = false;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Move Completed"));
}