// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Crate.h"
#include "MetalCrate.generated.h"

/**
 * 
 */
UCLASS()
class CRASHBANDICOOT_API AMetalCrate : public ACrate
{
	GENERATED_BODY()


public:

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	
};
