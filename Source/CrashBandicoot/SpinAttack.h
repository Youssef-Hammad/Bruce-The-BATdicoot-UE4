// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpinAttack.generated.h"

UCLASS()
class CRASHBANDICOOT_API ASpinAttack : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpinAttack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		class USceneComponent* RootComp;

	UPROPERTY(EditAnywhere)
		class USphereComponent* SphereCollision;

	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComp,
			AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void MyDestroy(AActor* actor);

	UPROPERTY(EditAnywhere)
		float BaseDamage;

};
