// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "NavigationSystem.h"
#include "AIEnemy.h"

AMyAIController::AMyAIController()
{
}

void AMyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	if (AAIEnemy* Enemy = Cast<AAIEnemy>(GetPawn()))
	{
		Enemy->OnMoveCompleted();
	}
}