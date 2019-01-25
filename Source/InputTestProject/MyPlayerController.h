// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

template<typename T>
inline int32 ToInt32(T _val)
{
	return static_cast<int32>(_val);
}

UENUM(BlueprintType)
enum class EMY_INPUT_TYPE : uint8
{
	KEY_UP,
	KEY_DOWN,
	KEY_RIGHT,
	KEY_LEFT,

	MAX,
};

/**
 * 
 */
UCLASS()
class INPUTTESTPROJECT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	TArray<bool> PastPressed;		// 1フレーム前の入力情報
	TArray<bool> CurrentPressed;	// 現フレームの入力情報

protected:
public:
	AMyPlayerController();

	virtual void Tick(float _deltaTime) override;

	UFUNCTION(BlueprintCallable)
	bool IsPressed(EMY_INPUT_TYPE _inputType);
	
	UFUNCTION(BlueprintCallable)
	bool IsPressHold(EMY_INPUT_TYPE _inputType);
	
	UFUNCTION(BlueprintCallable)
	bool IsReleased(EMY_INPUT_TYPE _inputType);
};
