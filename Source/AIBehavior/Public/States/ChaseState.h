// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "States/BaseState.h"
#include "ChaseState.generated.h"

/**
 * 
 */
UCLASS()
class AIBEHAVIOR_API UChaseState : public UBaseState
{
	GENERATED_BODY()

	void Update(AAIEnemy* character, float DeltaTime) override;
};
