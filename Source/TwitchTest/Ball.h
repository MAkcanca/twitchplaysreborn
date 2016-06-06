// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TwitchTest.h"
#include "GameFramework/Pawn.h"
#include "CommandRegistry.h"
#include "TwitchPawn.h"
#include "Ball.generated.h"

UCLASS()
class TWITCHTEST_API ABall : public ATwitchPawn
{
	GENERATED_BODY()

protected:
	FVector CurrentVelocity;

	/*
	ThreadRead* _run= NULL;
	FRunnableThread* _thread = NULL;
	FCommandRegistry CommandsRegistry;
	*/
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* OurVisibleComponent;

public:
	// Sets default values for this pawn's properties
	ABall();

	FVector GetCurrentVelocity() { return CurrentVelocity; }
	void SetCurrentVelocity(FVector velocity) { CurrentVelocity = velocity; }

	UStaticMeshComponent* GetOurVisibleComponent() { return OurVisibleComponent; }

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

};