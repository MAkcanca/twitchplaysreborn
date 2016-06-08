// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TwitchTest.h"
#include "CommandRegistry.h"

// Initialize static values
//const FCommandRegistry<>::FCommandRegistry<FWorldCommand> World;
TSet<FString> FCommandRegistry<>::ExistingKeywords;

bool FCommandRegistry<>::ExistsCommand(FString name)
{
	return ExistingKeywords.Contains(name);
}