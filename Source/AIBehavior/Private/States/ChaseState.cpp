// Fill out your copyright notice in the Description page of Project Settings.


#include "States/ChaseState.h"
#include "..\AIBehaviorcharacter.h"
#include "GameFramework/character.h"
#include <Kismet/GameplayStatics.h>
#include "FleeEnemy.h"
#include "ChaseEnemy.h"

void UChaseState::Update(AAIEnemy* character, float DeltaTime)
{
	// Chase the player
	FVector direction = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation() - character->GetActorLocation();
	direction.Normalize();

	// Move the character
	character->AddMovementInput(direction, 1.0f);

	// Calculate the distance to the player
	float distance = FVector::Dist(character->GetActorLocation(), UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation());

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