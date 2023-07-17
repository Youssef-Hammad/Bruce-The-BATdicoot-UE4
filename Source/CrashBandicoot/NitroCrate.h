// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Crate.h"
#include "NitroCrate.generated.h"

/**
 * 
 */
UCLASS()
class CRASHBANDICOOT_API ANitroCrate : public ACrate
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComp,
			AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};
