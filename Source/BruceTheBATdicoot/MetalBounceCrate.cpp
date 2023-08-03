// Fill out your copyright notice in the Description page of Project Settings.


#include "MetalBounceCrate.h"
#include "CrashBandicootCharacter.h"

void AMetalBounceCrate::BeginPlay()
{
    Super::BeginPlay();
}

void AMetalBounceCrate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

float AMetalBounceCrate::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
    return 0.0f;
}

void AMetalBounceCrate::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->GetName().Contains("ThirdPersonCharacter") && (bIsDimensionActive && bIsFirstDimension == Player->bIsFirstDimension) || !bIsDimensionActive)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hit Normal Z: %f"), Hit.Normal.Z);
		if (Hit.Normal.Z == -1.f)
		{
			Cast<ACrashBandicootCharacter>(OtherActor)->LaunchCharacter(LaunchVelocity, false, true);
		}

	}
}
