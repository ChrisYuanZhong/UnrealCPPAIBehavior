// Fill out your copyright notice in the Description page of Project Settings.


#include "States/DashState.h"
#include "FleeEnemy.h"
#include <States/FleeState.h>

void UDashState::Update(AAIEnemy* character, const float DeltaSeconds)
{
}

void UDashState::OnEnter(AAIEnemy* character)
{
	// Launch the character
	character->LaunchCharacter(character->GetActorForwardVector().GetSafeNormal() * DashSpeed, true, true);

	character->ChangeStateTo(UFleeState::StaticClass());
}

void UDashState::OnExit(AAIEnemy* character)
{
}