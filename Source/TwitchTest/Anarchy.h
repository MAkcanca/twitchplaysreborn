// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Strategy.h"

/**
 * 
 */
class TWITCHTEST_API Anarchy : public Strategy
{
public:
	 
	Anarchy(UWorld* w, BlockingQueue<FString>* q, int32 time, CampsManager* c) : Strategy(q, c) {
		world = w;
		FTimerDelegate del;
		del.BindLambda([this] {
			OnTick();
		});
		world->GetTimerManager().SetTimer(TimerHandle, del, time, true);
	};


	FTimerHandle TimerHandle;
	UWorld* world;

	void Receive(FString userName, FString message) override;
	void OnTick() override;

};
