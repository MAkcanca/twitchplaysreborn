// Fill out your copyright notice in the Description page of Project Settings.

#include "TwitchPlaysAPI.h"
#include "TwitchPawn.h"


// Sets default values
ATwitchPawn::ATwitchPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Set this pawn to be controlled by the lowest-numbered player
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void ATwitchPawn::BeginPlay()
{
	Super::BeginPlay();

	// Register commands
	RegisterCommands();
}

// Called every frame
void ATwitchPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATwitchPawn::BeginDestroy()
{
	Super::BeginDestroy();
	
	UE_LOG(LogTemp, Warning, TEXT("Ball: BeginDestroy"));

	//Kill the thread
	if (_thread)
	{
		_run->Stop();
		_thread->WaitForCompletion();
		delete _thread;
	}
}

void ATwitchPawn::setQueue(BlockingQueue<FCommandParser>* queue)
{
	_run = new ThreadRead(&CommandsRegistry);
	_run->SetQueue(queue);
}

void ATwitchPawn::setCamps(Camps* c)
{
	_run = new ThreadRead(&CommandsRegistry);
	_run->SetQueue(c->GetQueue());
}

void ATwitchPawn::launch()
{
	UE_LOG(LogTemp, Warning, TEXT("Twitch Read: Launch"));
	_thread = FRunnableThread::Create(_run, TEXT("FThreadRead"), 0, TPri_BelowNormal);
}
