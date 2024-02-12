// Fill out your copyright notice in the Description page of Project Settings.


#include "States/FleeState.h"
#include "..\AIBehaviorCharacter.h"
#include "GameFramework/Character.h"
#include <Kismet/GameplayStatics.h>
#include "FleeEnemy.h"
#include "ChaseEnemy.h"

void UFleeState::Update(AAIEnemy* character, float DeltaTime)
{
	// Flee from the player
	FVector direction = character->GetActorLocation() - UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();
	direction.Normalize();

	// Move the character
	character->AddMovementInput(direction, 1.0f);

	// Calculate the distance to the player
	float distance = FVector::Dist(character->GetActorLocation(), UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation());

	// Check if the player is far enough to the AI
	if (distance > character->RangeOfSight)
	{
		// Change the state to Wander

	}
	else if (distance < character->RangeOfDanger)
	{
		// Change the state to Dash

	}
}