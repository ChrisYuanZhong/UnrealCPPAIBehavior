// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "States/BaseState.h"
#include "AttackState.generated.h"

/**
 * 
 */
UCLASS()
class AIBEHAVIOR_API UAttackState : public UBaseState
{
	GENERATED_BODY()
	
public:
	void OnEnter(AAIEnemy* character) override;

private:
	UPROPERTY(EditAnywhere, Category = "Attack")
	float JumpForce = 800.0f;
};
