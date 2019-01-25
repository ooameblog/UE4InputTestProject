// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"

#include "EngineGlobals.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "MyPlayerController.h"

AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();
}

void AMyActor::Tick(float _deltaTime)
{
	Super::Tick(_deltaTime);

	AMyPlayerController* MyController = 
		Cast<AMyPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	if (MyController)
	{
		// ↑キー入力処理
		if (MyController->IsPressed(EMY_INPUT_TYPE::KEY_UP))
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString(TEXT("Press UP Key!")));
		}
		if (MyController->IsPressHold(EMY_INPUT_TYPE::KEY_UP))
		{
			MoveForward(_deltaTime);
		}
		if (MyController->IsReleased(EMY_INPUT_TYPE::KEY_UP))
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString(TEXT("Release UP Key!")));
		}

		// ↓キー入力処理
		if (MyController->IsPressed(EMY_INPUT_TYPE::KEY_DOWN))
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString(TEXT("Press Down Key!")));
		}
		if (MyController->IsPressHold(EMY_INPUT_TYPE::KEY_DOWN))
		{
			MoveBackward(_deltaTime);
		}
		if (MyController->IsReleased(EMY_INPUT_TYPE::KEY_DOWN))
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString(TEXT("Release Down Key!")));
		}

		// →キー入力処理
		if (MyController->IsPressed(EMY_INPUT_TYPE::KEY_RIGHT))
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, FString(TEXT("Press Right Key!")));
		}
		if (MyController->IsPressHold(EMY_INPUT_TYPE::KEY_RIGHT))
		{
			TurnRight(_deltaTime);
		}
		if (MyController->IsReleased(EMY_INPUT_TYPE::KEY_RIGHT))
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, FString(TEXT("Release Right Key!")));
		}

		// ←キー入力処理
		if (MyController->IsPressed(EMY_INPUT_TYPE::KEY_LEFT))
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString(TEXT("Press Left Key!")));
		}
		if (MyController->IsPressHold(EMY_INPUT_TYPE::KEY_LEFT))
		{
			TurnLeft(_deltaTime);
		}
		if (MyController->IsReleased(EMY_INPUT_TYPE::KEY_LEFT))
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString(TEXT("Release Left Key!")));
		}
	}
}
