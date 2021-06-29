// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnBox.h"

// Sets default values
ASpawnBox::ASpawnBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnBox::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ASpawnBox::CreateBox, createTime, true, 1);
}

// Called every frame
void ASpawnBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
// 박스생성
void ASpawnBox::CreateBox()
{
	FActorSpawnParameters Param;
	Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	GetWorld()->SpawnActor<ABoxActor>(BoxActor,
		GetActorLocation(),
		GetActorRotation(), Param);

	UE_LOG(LogTemp, Warning, TEXT("Actor 생성"));
}

