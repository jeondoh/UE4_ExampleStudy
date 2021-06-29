// Fill out your copyright notice in the Description page of Project Settings.


// #include "FloatingActor.h"
#include "Document/Public/FloatingActor.h"

#include "Particles/ParticleSystemComponent.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Particle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));
	RootComponent = Body;
	Particle->SetupAttachment(Body);
	
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();
	float DeltaHight = FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime);
	NewLocation.Z += DeltaHight * 20.0f;
	NewLocation.Y += DeltaHight * 20.0f;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);
}

