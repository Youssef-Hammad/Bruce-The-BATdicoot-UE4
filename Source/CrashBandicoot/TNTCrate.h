// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Crate.h"
#include "TNTCrate.generated.h"

/**
 * 
 */
UCLASS()
class CRASHBANDICOOT_API ATNTCrate : public ACrate
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:

	ATNTCrate();



	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	bool isHit;

	UPROPERTY(EditAnywhere)
	FVector LaunchVelocity;
	
};
