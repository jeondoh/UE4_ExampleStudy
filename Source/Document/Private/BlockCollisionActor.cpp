// Fill out your copyright notice in the Description page of Project Settings.

#include "BlockCollisionActor.h"

// Sets default values
ABlockCollisionActor::ABlockCollisionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
}

// Called when the game starts or when spawned
void ABlockCollisionActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABlockCollisionActor::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
}

// Called every frame
void ABlockCollisionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

