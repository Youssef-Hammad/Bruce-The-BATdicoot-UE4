// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IdleRotation.generated.h"

UCLASS()
class BRUCETHEBATDICOOT_API AIdleRotation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AIdleRotation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		class USceneComponent* RootComp;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* SM1;
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* SM2;
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* SM3;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* BoxCollision;

	UPROPERTY(EditAnywhere)
		float RotationRate;

	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
