// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Strategy.h"

/**
 * 
 */
class TWITCHTEST_API Democracy : public Strategy
{
private:
	TMap<FString, int> commands;

	FTimerHandle TimerHandle;
	UWorld* world;

public:

	Democracy(UWorld* _world, BlockingQueue<FCommandParser>* _queue, int32 time, GameContext* _context)
		: Strategy(_queue, _context), world(_world) {
		FTimerDelegate del;
		del.BindLambda([this] {
			OnTick();
		});
		world->GetTimerManager().SetTimer(TimerHandle, del, time, true);
	};

	void Receive(FCommandParser parser) override;
	void OnTick() override;
};