// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraModifier.h"
#include "TunnelCamModifier.generated.h"

/**
 * 
 */
UCLASS()
class CRASHBANDICOOT_API UTunnelCamModifier : public UCameraModifier
{
	GENERATED_BODY()

public:

	UTunnelCamModifier();

	UFUNCTION(BlueprintCallable)
	virtual bool ModifyCamera(float DeltaTime, struct FMinimalViewInfo& InOutPOV) override;

	UPROPERTY(EditAnywhere)
	FVector TunnelZ = FVector(0.f,0.f,200.f);

private:

	UPROPERTY(EditAnywhere)
	float InterpSpeed;
	
};
