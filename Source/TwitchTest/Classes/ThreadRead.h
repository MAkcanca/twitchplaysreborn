// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TwitchPlaysAPI.h"
#include "BlockingQueue.h"
#include "TwitchMessageReceiver.h"
#include "CommandRegistry.h"

/**
 * Thread receiving messages from the Twitch message receiver.
 */
class ThreadRead : public FRunnable
{
public:
	bool running = true;
	int32 nb_camps;
	BlockingQueue<FCommandParser>* queue;

protected:
	// Twitch messages queue
	TQueue<FString>* CommandsQueue;// = &FTwitchMessageReceiver::MessagesQueue;

	// Commands registry
	FCommandRegistry* CommandsRegistry;

public:
	ThreadRead(FCommandRegistry* Commandes);
	virtual bool Init();
	virtual uint32 Run();
	virtual void Stop();
	virtual void SetQueue(BlockingQueue<FCommandParser>* queue);
};
