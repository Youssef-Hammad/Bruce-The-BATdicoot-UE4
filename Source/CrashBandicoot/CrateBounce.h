// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Crate.h"
#include "CrateBounce.generated.h"

/**
 * 
 */
UCLASS()
class CRASHBANDICOOT_API ACrateBounce : public ACrate
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:

	ACrateBounce();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
private:
	
	UPROPERTY(EditAnywhere, meta = (AloowPrivateAccess = "true"))
	int Hits;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	FVector LaunchVelocity;
};
