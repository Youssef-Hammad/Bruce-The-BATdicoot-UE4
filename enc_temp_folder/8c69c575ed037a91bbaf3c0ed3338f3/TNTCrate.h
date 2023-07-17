// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Crate.h"
#include "TNTCrate.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIsBombTriggered, FTimerHandle, BombTimer);

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

	void MyDestroy();

	bool isHit;

	UPROPERTY(EditAnywhere)
	FVector LaunchVelocity;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FTimerHandle BombTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FIsBombTriggered BombTriggeredDelegate;
	
};
