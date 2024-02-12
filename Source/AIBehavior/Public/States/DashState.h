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
	
	void OnEnter(AAIEnemy* character) override;
};
