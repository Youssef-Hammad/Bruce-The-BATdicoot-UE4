// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CrashCamera.generated.h"

UCLASS()
class CRASHBANDICOOT_API ACrashCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACrashCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float Pitch_Offset = -40.f;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* DefaultRoot;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class USplineComponent* Spline;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class ACharacter* Crash;

};
