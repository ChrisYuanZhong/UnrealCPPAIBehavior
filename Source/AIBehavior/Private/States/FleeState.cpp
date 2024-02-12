// Fill out your copyright notice in the Description page of Project Settings.


#include "States/FleeState.h"
#include "..\AIBehaviorCharacter.h"
#include "GameFramework/Character.h"
#include <Kismet/GameplayStatics.h>
#include "FleeEnemy.h"
#include "ChaseEnemy.h"
#include <States/WanderState.h>
#include <States/DashState.h>
#include <NavigationSystem.h>
#include <MyAIController.h>
#include <GameFramework/CharacterMovementComponent.h>

void UFleeState::Update(AAIEnemy* character, const float DeltaTime)
{
	//// Flee from the player
	//FVector direction = character->GetActorLocation() - UGameplayStatics::GetPlayerCharacter(character->GetWorld(), 0)->GetActorLocation();
	//direction.Normalize();

	//// Move the character
	//character->AddMovementInput(direction, 1.0f);

	FNavLocation destination;

	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(character->GetWorld());
	if (NavSystem)
	{
		// Get the player location
		FVector playerLocation = UGameplayStatics::GetPlayerCharacter(character->GetWorld(), 0)->GetActorLocation();

		// Get the flee location
		FVector fleeLocation = character->GetActorLocation() + (character->GetActorLocation() - playerLocation).GetSafeNormal() * 100.0f;

		// Get the nearest point on the nav mesh
		NavSystem->ProjectPointToNavigation(fleeLocation, destination);

		// Move the character
		AMyAIController* AIController = Cast<AMyAIController>(character->GetController());
		AIController->MoveToLocation(destination.Location, 5.0f);
	}

	// Calculate the distance to the player
	float distance = FVector::Dist(character->GetActorLocation(), UGameplayStatics::GetPlayerCharacter(character->GetWorld(), 0)->GetActorLocation());

	// Check if the player is far enough to the AI
	if (distance > character->RangeOfSight)
	{
		// Change the state to Wander
		// Print a message
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("To Wander"));

		AFleeEnemy* fleeEnemy = Cast<AFleeEnemy>(character);
		fleeEnemy->ChangeStateTo(UWanderState::StaticClass());
	}
	else if (distance < character->RangeOfDanger)
	{
		// Change the state to Dash

	}
}

void UFleeState::OnEnter(AAIEnemy* character)
{
	// Set the speed of the character
	UCharacterMovementComponent* CharacterMovement = Cast<UCharacterMovementComponent>(character->GetMovementComponent());
	CharacterMovement->MaxWalkSpeed = FleeSpeed;
}