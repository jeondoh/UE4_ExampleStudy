// Fill out your copyright notice in the Description page of Project Settings.


#include "BoxColorPawn.h"

// Sets default values
ABoxColorPawn::ABoxColorPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
}

// Called when the game starts or when spawned
void ABoxColorPawn::BeginPlay()
{
	Super::BeginPlay();
	UStaticMeshComponent* Cube = FindComponentByClass<UStaticMeshComponent>();
	UMaterialInterface* Mat = Cube->GetMaterial(0);

	DynamicMat = UMaterialInstanceDynamic::Create(Mat, NULL);
	Cube->SetMaterial(0, DynamicMat);

	ColorFlag = true; // 색 변경 변수
}

// Called every frame
void ABoxColorPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABoxColorPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(TEXT("ColorChange"), IE_Pressed, this, &ABoxColorPawn::InputColorChange);
	UE_LOG(LogTemp, Warning, TEXT("CLICK"));
}

void ABoxColorPawn::InputColorChange()
{
	if(ColorFlag)
	{
		VectorParameter = FLinearColor(0.13f, 0.17f, 0.13f);
		ColorFlag=false;
	}
	else
	{
		VectorParameter = FLinearColor(0.88f, 0.31f, 0.81f);
		ColorFlag=true;
	}
	DynamicMat->SetVectorParameterValue(TEXT("VColor"), VectorParameter);
	// float blend = 0.5f + FMath::Cos(GetWorld()->TimeSeconds)/2;
	// DynamicMat->SetScalarParameterValue(TEXT("BoxColor"), blend);
}