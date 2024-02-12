// Fill out your copyright notice in the Description page of Project Settings.


#include "States/ChaseState.h"
#include <Kismet/GameplayStatics.h>
#include "FleeEnemy.h"
#include "ChaseEnemy.h"
#include <States/WanderState.h>
#include <States/AttackState.h>
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
		AChaseEnemy* chaseEnemy = Cast<AChaseEnemy>(character);
		chaseEnemy->ChangeStateTo(UWanderState::StaticClass());

	}
	else if (distance < character->RangeOfDanger)
	{
		// If the character is not in the air
		if (!character->GetCharacterMovement()->IsFalling())
		{
			// Change the state to Attack
			AChaseEnemy* chaseEnemy = Cast<AChaseEnemy>(character);
			chaseEnemy->ChangeStateTo(UAttackState::StaticClass());
		}
	}
}

void UChaseState::OnEnter(AAIEnemy* character)
{
	// Set the speed of the character
	UCharacterMovementComponent* CharacterMovement = Cast<UCharacterMovementComponent>(character->GetMovementComponent());
	CharacterMovement->MaxWalkSpeed = ChaseSpeed;
}