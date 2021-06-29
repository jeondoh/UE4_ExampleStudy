// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "BoxActor.h"
#include "GameFramework/Actor.h"
#include "SpawnBox.generated.h"

UCLASS()
class DOCUMENT_API ASpawnBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnBox();

	UPROPERTY()
	FTimerHandle TimerHandle;
	
	UPROPERTY(EditDefaultsOnly, Category = "BoxClass")
	TSubclassOf<ABoxActor> BoxActor;
	
	UPROPERTY(EditAnywhere, Category="Time")
	float createTime = 9;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void CreateBox();


};
