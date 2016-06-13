// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameContext.h"
#include "BlockingQueue.h"
#include "Command.h"

#define STRAT_BASIC    0
#define STRAT_ANARCHY  1

/**
 * 
 */
class TWITCHTEST_API Strategy
{
protected:
	GameContext* Context;
	BlockingQueue<FCommandParser>* queue;
	TArray<TMap<FString, FCommandParser>> Messages;
	bool multicamps = true;

	static TMap<FString, int32> StrategyMap;

public:
	Strategy(BlockingQueue<FCommandParser>* _queue, GameContext* _context);

	virtual void Receive(FCommandParser parser);
	virtual void OnTick();

	// === Strategy types management

	static TMap<FString, int32> BasicStrategyMap() {
		TMap<FString, int32> StratsMap;

		// Basic strategies
		StratsMap.Add(TEXT("basic"), STRAT_BASIC);
		StratsMap.Add(TEXT("anarchy"), STRAT_ANARCHY);

		return StratsMap;
	}

	static int32 FindStrategy(FString strategyName) {
		return StrategyMap.FindRef(strategyName);
	}

	static void AddStrategy(FString strategyName, int32 strategy) {
		StrategyMap.Add(strategyName, strategy);
	}
};
