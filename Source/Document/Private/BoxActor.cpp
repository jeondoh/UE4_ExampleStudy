// Fill out your copyright notice in the Description page of Project Settings.


#include "BoxActor.h"

#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ABoxActor::ABoxActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}

// Called when the game starts or when spawned
void ABoxActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABoxActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(IsValid(this))
	{
		WaitTime += DeltaTime;
		if(WaitTime >= DestroyTime)
		{
			// 폭발 사운드
			UGameplayStatics::PlaySound2D(GetWorld(), ExplosionSound); 
			// 폭발효과
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticle, GetActorTransform());
			// 폭발 후 잔여효과
			ParticleSystemComponent = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticle2, GetActorTransform());
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ABoxActor::RemoveFire, 3, false, 0);
			
			this->Destroy();
			UE_LOG(LogTemp, Warning, TEXT("Actor 삭제"));
			WaitTime = 0;
		}
	}

}

void ABoxActor::RemoveFire()
{
	UE_LOG(LogTemp, Warning, TEXT("bbbbbbb"));
	ParticleSystemComponent->Deactivate();
}

