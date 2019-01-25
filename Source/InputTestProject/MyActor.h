// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class INPUTTESTPROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()
	
private:	
protected:
public:	
	AMyActor();

	virtual void BeginPlay() override;
	virtual void Tick(float _deltaTime) override;
	
	UFUNCTION(BlueprintImplementableEvent)
	void MoveForward(float _deltaTime);

	UFUNCTION(BlueprintImplementableEvent)
	void MoveBackward(float _deltaTime);

	UFUNCTION(BlueprintImplementableEvent)
	void TurnRight(float _deltaTime);

	UFUNCTION(BlueprintImplementableEvent)
	void TurnLeft(float _deltaTime);
};
