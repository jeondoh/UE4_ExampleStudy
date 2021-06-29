// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BoxColorPawn.generated.h"

UCLASS()
class DOCUMENT_API ABoxColorPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABoxColorPawn();

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UStaticMeshComponent* MeshComp;

	UPROPERTY()
	class UMaterialInstanceDynamic* DynamicMat;

	UPROPERTY()
	FLinearColor VectorParameter;

	UPROPERTY()
	bool ColorFlag;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// ColorChange(T) 키를 눌렀을 경우
	void InputColorChange();
	
};
