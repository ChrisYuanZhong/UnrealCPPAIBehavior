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

public:
	void Update(AAIEnemy* character, const float DeltaTime) override;

	void OnEnter(AAIEnemy* character) override;

private:
	UPROPERTY(EditAnywhere, Category = "Chase")
	float ChaseSpeed = 400.0f;
};
