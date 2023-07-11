// Fill out your copyright notice in the Description page of Project Settings.


#include "TunnelCamModifier.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/PlayerCameraManager.h"
#include "Math/UnrealMathUtility.h"

UTunnelCamModifier::UTunnelCamModifier()
{
	AlphaInTime = .5f;
	AlphaOutTime = .5f;
	InterpSpeed = 3.f;
}

bool UTunnelCamModifier::ModifyCamera(float DeltaTime, struct FMinimalViewInfo& InOutPOV)
{
	FVector Target = InOutPOV.Location - TunnelZ;
	FRotator RTarget = InOutPOV.Rotation + FRotator(30, 0, 0);
	APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	InOutPOV.Location = FMath::VInterpTo(CameraManager->GetCameraLocation(), Target, DeltaTime, InterpSpeed);
	InOutPOV.Rotation = FMath::RInterpTo(CameraManager->GetCameraRotation(), RTarget, DeltaTime, InterpSpeed);
	UE_LOG(LogTemp, Warning, TEXT("Triggered"));
	return true;
}
