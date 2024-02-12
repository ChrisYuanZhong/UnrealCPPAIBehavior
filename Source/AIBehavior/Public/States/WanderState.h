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
	void Update(AAIEnemy* character, const float DeltaTime) override;

	void OnEnter(AAIEnemy* character) override;

	void NewDestination(AAIEnemy* character);

	void SetNotMoving();

private:
	UPROPERTY(EditAnywhere, Category = "Wander")
	float WanderRadius = 1000.0f;

	UPROPERTY(EditAnywhere, Category = "Wander")
	float WanderSpeed = 300.0f;

	bool bIsMoving = false;
};
