// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"

AMyPlayerController::AMyPlayerController()
{
	PastPressed.Init(false, ToInt32(EMY_INPUT_TYPE::MAX));
	CurrentPressed.Init(false, ToInt32(EMY_INPUT_TYPE::MAX));
}

void AMyPlayerController::Tick(float _deltaTime)
{
	PastPressed = CurrentPressed;

	// ì¸óÕèÓïÒÇÃçXêV
	CurrentPressed[ToInt32(EMY_INPUT_TYPE::KEY_UP)]	  = IsInputKeyDown(EKeys::Up);
	CurrentPressed[ToInt32(EMY_INPUT_TYPE::KEY_DOWN)]  = IsInputKeyDown(EKeys::Down);
	CurrentPressed[ToInt32(EMY_INPUT_TYPE::KEY_RIGHT)] = IsInputKeyDown(EKeys::Right);
	CurrentPressed[ToInt32(EMY_INPUT_TYPE::KEY_LEFT)]  = IsInputKeyDown(EKeys::Left);
}

bool AMyPlayerController::IsPressed(EMY_INPUT_TYPE _inputType)
{
	bool pp = PastPressed[ToInt32(_inputType)];
	bool cp = CurrentPressed[ToInt32(_inputType)];

	return ((pp ^ cp) & (!pp));
}

bool AMyPlayerController::IsPressHold(EMY_INPUT_TYPE _inputType)
{
	return CurrentPressed[ToInt32(_inputType)];
}

bool AMyPlayerController::IsReleased(EMY_INPUT_TYPE _inputType)
{
	bool pp = PastPressed[ToInt32(_inputType)];
	bool cp = CurrentPressed[ToInt32(_inputType)];

	return ((pp ^ cp) & (pp));
}
