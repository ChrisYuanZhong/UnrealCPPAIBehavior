// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "States/BaseState.h"
#include "DashState.generated.h"

/**
 * 
 */
UCLASS()
class AIBEHAVIOR_API UDashState : public UBaseState
{
	GENERATED_BODY()

public:
	void Update(AAIEnemy* character, const float DeltaSeconds) override;
	
	void OnEnter(AAIEnemy* character) override;

	void OnExit(AAIEnemy* character) override;

private:
	UPROPERTY(EditAnywhere, Category = "Dash")
	float DashSpeed = 5000.0f;
};
