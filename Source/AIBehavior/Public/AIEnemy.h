// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <States/BaseState.h>
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIEnemy.generated.h"

UCLASS()
class AIBEHAVIOR_API AAIEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAIEnemy();

	// State Machine
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "State Machine")
	TObjectPtr<UBaseState> CurrentState;

	// Range of Sight
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float RangeOfSight = 1000.0f;

	// Range of Danger
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float RangeOfDanger = 200.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "State Machine")
	void ChangeStateTo(const TSubclassOf<UBaseState> NewState);

	UFUNCTION(BlueprintCallable, Category = "State Machine")
	void OnStateChange();

	UFUNCTION(BlueprintCallable)
	void OnMoveCompleted();
};
