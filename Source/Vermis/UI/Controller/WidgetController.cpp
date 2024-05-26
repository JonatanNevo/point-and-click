// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetController.h"

void UWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& Params)
{
	PlayerController = Params.PlayerController;
	PlayerState = Params.PlayerState;
}

void UWidgetController::BindCallbacksToDependencies()
{
}
