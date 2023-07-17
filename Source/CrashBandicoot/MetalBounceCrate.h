// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Crate.h"
#include "MetalBounceCrate.generated.h"

/**
 * 
 */
UCLASS()
class CRASHBANDICOOT_API AMetalBounceCrate : public ACrate
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
public:
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		FVector LaunchVelocity;
};
