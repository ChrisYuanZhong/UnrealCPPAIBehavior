// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "States/BaseState.h"
#include "WanderState.generated.h"

/**
 * 
 */
UCLASS()
class AIBEHAVIOR_API UWanderState : public UBaseState
{
	GENERATED_BODY()
	
public:
	void Update(AAIEnemy* character, float DeltaTime) override;

	void NewDestination(AAIEnemy* character);

private:
	UPROPERTY(EditAnywhere, Category = "Wander")
	float WanderRadius = 1000.0f;
};
