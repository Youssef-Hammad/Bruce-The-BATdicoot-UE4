// Fill out your copyright notice in the Description page of Project Settings.


#include "MetalCrate.h"

void AMetalCrate::BeginPlay()
{
    Super::BeginPlay();
}

void AMetalCrate::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

float AMetalCrate::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
    return 0.0f;
}
