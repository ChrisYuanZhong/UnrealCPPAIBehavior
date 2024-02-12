// Fill out your copyright notice in the Description page of Project Settings.


#include "States/ChaseState.h"
#include "..\AIBehaviorcharacter.h"
#include "GameFramework/character.h"
#include <Kismet/GameplayStatics.h>
#include "FleeEnemy.h"
#include "ChaseEnemy.h"
#include <NavigationSystem.h>
#include <MyAIController.h>
#include <GameFramework/CharacterMovementComponent.h>

void UChaseState::Update(AAIEnemy* character, const float DeltaTime)
{
	// Chase the player
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(character->GetWorld());
	if (NavSystem)
	{
		// Move the character
		ACharacter* player = UGameplayStatics::GetPlayerCharacter(character->GetWorld(), 0);
		AMyAIController* AIController = Cast<AMyAIController>(character->GetController());
		AIController->MoveToActor(player);
	}

	// Calculate the distance to the player
	float distance = FVector::Dist(character->GetActorLocation(), UGameplayStatics::GetPlayerCharacter(character->GetWorld(), 0)->GetActorLocation());

	// Check the distance to the player
	if (distance > character->RangeOfSight)
	{
		// Change the state to Wander

	}
	else if (distance < character->RangeOfDanger)
	{
		// Change the state to Attack

	}
}

void UChaseState::OnEnter(AAIEnemy* character)
{
	// Set the speed of the character
	UCharacterMovementComponent* CharacterMovement = Cast<UCharacterMovementComponent>(character->GetMovementComponent());
	CharacterMovement->MaxWalkSpeed = ChaseSpeed;
}