// Fill out your copyright notice in the Description page of Project Settings.


#include "States/AttackState.h"
#include "ChaseEnemy.h"
#include <States/ChaseState.h>
#include <Kismet/GameplayStatics.h>

void UAttackState::OnEnter(AAIEnemy* character)
{
	// Attack the player
	// Lauch the character to above the player
	character->LaunchCharacter(((UGameplayStatics::GetPlayerCharacter(character->GetWorld(), 0)->GetActorLocation() - character->GetActorLocation()).GetSafeNormal() + FVector(0, 0, 2)).GetSafeNormal() * JumpForce, true, true);

	// After attacking the player, transition to the Chase state
	character->ChangeStateTo(UChaseState::StaticClass());
}