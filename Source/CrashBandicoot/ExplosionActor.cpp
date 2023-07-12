// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplosionActor.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AExplosionActor::AExplosionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ExplosionParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ExplosionParticles"));
	RadialBaseDamage = 1.0f;
	DamageRadius = 80.f;

	this->InitialLifeSpan = .5f;
}

// Called when the game starts or when spawned
void AExplosionActor::BeginPlay()
{
	Super::BeginPlay();

	ExplosionParticles->Activate();
	UGameplayStatics::ApplyRadialDamage(GetWorld(), RadialBaseDamage, GetActorLocation(), DamageRadius, nullptr, TArray<AActor*>(), this, nullptr, true);
	
}

// Called every frame
void AExplosionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

