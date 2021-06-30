// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraDirector.h"
#include <kismet/GameplayStatics.h>

// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	const float TimeBetweenCameraChanges = 2.0f; // 상수
	const float SmoothBlendTime = 0.75f;

	TimeToNextCameraChange -=DeltaTime;
	if(TimeToNextCameraChange <= 0.0f)
	{
		FCameraStruct NowCamera = Cameras[NowCameraIndex];
		
		TimeToNextCameraChange += NowCamera.TimeBetweenCameraChanges;
		APlayerController* controller = UGameplayStatics::GetPlayerController(this, 0);
		if(controller)
		{
			if((controller->GetViewTarget() != NowCamera.camera) && (NowCamera.camera != nullptr))
			{
				if (NowCamera.SmoothBlendTime <= 0.0f)
				{
					controller->SetViewTarget(NowCamera.camera);
				}
				else
				{
					controller->SetViewTargetWithBlend(NowCamera.camera, NowCamera.SmoothBlendTime);					
				}

				
			}
			// 카메라 전환
			// if((controller->GetViewTarget() != CameraOne) && (CameraOne != nullptr))
			// {
			// 	controller->SetViewTarget(CameraOne);
			// }
			// else if ((controller->GetViewTarget() != CameraTwo) && (CameraTwo != nullptr))
			// {
			// 	controller->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
			// }
		}
		NowCameraIndex++;
		if(NowCameraIndex >= Cameras.Num())
		{
			NowCameraIndex = 0;
		}
	}
}

