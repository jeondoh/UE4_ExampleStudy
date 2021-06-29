// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "BoxActor.generated.h"

UCLASS()
class DOCUMENT_API ABoxActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoxActor();
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, Category="Time")
	float DestroyTime = 3;

	UPROPERTY()
	float WaitTime = 0;

	UPROPERTY()
	FTimerHandle TimerHandle;

	UPROPERTY()
	FVector BoxLocation;

	// 폭발효과 속성
	UPROPERTY(EditAnywhere, Category = "Setting")
	class UParticleSystem* ExplosionParticle;
	// 폭발 후 잔여효과
	UPROPERTY(EditAnywhere, Category = "Setting")
	class UParticleSystem* ExplosionParticle2;

	UPROPERTY()
	class UParticleSystemComponent* ParticleSystemComponent;
	
	// 폭발 사운드
	UPROPERTY(EditAnywhere, Category = "Setting")
	class USoundBase* ExplosionSound;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void RemoveFire();
};
