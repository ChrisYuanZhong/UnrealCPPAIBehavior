// Fill out your copyright notice in the Description page of Project Settings.


#include "States/WanderState.h"
#include "AIEnemy.h"
#include <Kismet/GameplayStatics.h>
#include "FleeEnemy.h"
#include "ChaseEnemy.h"
#include <States/FleeState.h>
#include <States/ChaseState.h>
#include <States/AttackState.h>
#include <States/DashState.h>
#include <NavigationSystem.h>
#include <MyAIController.h>
#include <GameFramework/CharacterMovementComponent.h>

void UWanderState::Update(AAIEnemy* character, const float DeltaTime)
{
	// Wander around
	if (!bIsMoving)
	{
		// Set a new destination
		NewDestination(character);
		bIsMoving = true;
	}

	// Calculate the distance to the player
	float distance = FVector::Dist(character->GetActorLocation(), UGameplayStatics::GetPlayerCharacter(character->GetWorld(), 0)->GetActorLocation());

	// Check if the player is close enough to the AI
	if (distance < character->RangeOfDanger)
	{
		// If the character is a FleeEnemy
		if (character->IsA(AFleeEnemy::StaticClass()))
		{
			// Change the state to Dash
			// Print a message
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("To Dash"));

			AFleeEnemy* fleeEnemy = Cast<AFleeEnemy>(character);
			fleeEnemy->ChangeStateTo(UDashState::StaticClass());
		}
		// If the character is a ChaseEnemy
		else if (character->IsA(AChaseEnemy::StaticClass()))
		{
			// Change the state to Attack
			// Print a message
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("To Attack"));

			AChaseEnemy* chaseEnemy = Cast<AChaseEnemy>(character);
			chaseEnemy->ChangeStateTo(UAttackState::StaticClass());
		}
	}
	else if (distance < character->RangeOfSight)
	{
		// If the character is a FleeEnemy
		if (character->IsA(AFleeEnemy::StaticClass()))
		{
			// Change the state to Flee
			AFleeEnemy* fleeEnemy = Cast<AFleeEnemy>(character);
			fleeEnemy->ChangeStateTo(UFleeState::StaticClass());
		}
		// If the character is a ChaseEnemy
		else if (character->IsA(AChaseEnemy::StaticClass()))
		{
			// Change the state to Chase
			AChaseEnemy* chaseEnemy = Cast<AChaseEnemy>(character);
			chaseEnemy->ChangeStateTo(UChaseState::StaticClass());

		}
	}
}

void UWanderState::OnEnter(AAIEnemy* character)
{
	// Set the speed of the character
	UCharacterMovementComponent* CharacterMovement = Cast<UCharacterMovementComponent>(character->GetMovementComponent());
	CharacterMovement->MaxWalkSpeed = WanderSpeed;
}

void UWanderState::NewDestination(AAIEnemy* character)
{
	FNavLocation destination;

	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(character->GetWorld());
	if (NavSystem)
	{
		if (NavSystem->GetRandomPointInNavigableRadius(character->GetActorLocation(), WanderRadius, destination))
		{
			// Use AI MoveTo to move to the destination
			AMyAIController* AIController = Cast<AMyAIController>(character->GetController());
			AIController->MoveToLocation(destination.Location, 5.0f);
		}
	}
}

void UWanderState::SetNotMoving()
{
	bIsMoving = false;
}