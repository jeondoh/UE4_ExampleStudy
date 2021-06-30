// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraDirector.generated.h"

USTRUCT(Atomic, BlueprintType)
struct FCameraStruct
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* camera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeBetweenCameraChanges;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SmoothBlendTime;
};

UCLASS()
class DOCUMENT_API ACameraDirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraDirector();

	UPROPERTY(EditAnywhere)
	TArray<FCameraStruct> Cameras;

	int32 NowCameraIndex;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// UPROPERTY(EditAnywhere)
	// AActor* CameraOne;
	// UPROPERTY(EditAnywhere)
	// AActor* CameraTwo;
	UPROPERTY(EditAnywhere)
	float TimeToNextCameraChange;
};
