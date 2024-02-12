// Fill out your copyright notice in the Description page of Project Settings.


#include "States/WanderState.h"
#include "AIEnemy.h"
#include "GameFramework/Character.h"
#include <Kismet/GameplayStatics.h>
#include "FleeEnemy.h"
#include "ChaseEnemy.h"
#include <States/FleeState.h>
#include <NavigationSystem.h>
#include <MyAIController.h>
#include <GameFramework/CharacterMovementComponent.h>

void UWanderState::Update(AAIEnemy* character, float DeltaTime)
{
	// Wander around
	if (!character->bIsMoving)
	{
		// Set a new destination
		NewDestination(character);
		character->bIsMoving = true;
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
		}
		// If the character is a ChaseEnemy
		else if (character->IsA(AChaseEnemy::StaticClass()))
		{
			// Change the state to Attack
			// Print a message
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("To Attack"));
		}
	}
	else if (distance < character->RangeOfSight)
	{
		// If the character is a FleeEnemy
		if (character->IsA(AFleeEnemy::StaticClass()))
		{
			// Change the state to Flee
			// Print a message
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("To Flee"));

			//AFleeEnemy* fleeEnemy = Cast<AFleeEnemy>(character);
			//fleeEnemy->CurrentState = NewObject<UFleeState>();
		}
		// If the character is a ChaseEnemy
		else if (character->IsA(AChaseEnemy::StaticClass()))
		{
			// Change the state to Chase
			// Print a message
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("To Chase"));

			//AChaseEnemy* chaseEnemy = Cast<AChaseEnemy>(character);
			//chaseEnemy->CurrentState = NewObject<UChaseState>();

		}
	}
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