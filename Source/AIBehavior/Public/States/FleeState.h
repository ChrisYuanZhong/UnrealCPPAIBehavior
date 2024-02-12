// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "States/BaseState.h"
#include "FleeState.generated.h"

/**
 * 
 */
UCLASS()
class AIBEHAVIOR_API UFleeState : public UBaseState
{
	GENERATED_BODY()
	
public:
	void Update(AAIEnemy* character, const float DeltaTime) override;

	void OnEnter(AAIEnemy* character) override;

private:
	UPROPERTY(EditAnywhere, Category = "Flee")
	float FleeSpeed = 400.0f;
};
