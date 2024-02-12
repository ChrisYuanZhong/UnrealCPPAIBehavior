// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class AIBEHAVIOR_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
    // Constructor
    AMyAIController();

    // Override OnMoveCompleted to handle movement completion
    virtual void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;
};
