// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExplosionActor.generated.h"

UCLASS()
class CRASHBANDICOOT_API AExplosionActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExplosionActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	class UParticleSystemComponent* ExplosionParticles;

	UPROPERTY(EditAnywhere)
	float RadialBaseDamage;

	UPROPERTY(EditAnywhere)
	float DamageRadius;

};
