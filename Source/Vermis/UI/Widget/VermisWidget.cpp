﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "VermisWidget.h"

void UVermisWidget::SetWidgetController(UObject* Controller)
{
	WidgetController = Controller;
	WidgetControllerSet();
}
