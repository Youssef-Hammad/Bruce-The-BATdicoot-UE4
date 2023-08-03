// Fill out your copyright notice in the Description page of Project Settings.


#include "TNTCrate.h"
#include "CrashBandicootCharacter.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ExplosionActor.h"


ATNTCrate::ATNTCrate()
{
	isHit = false;

}

void ATNTCrate::BeginPlay()
{
	Super::BeginPlay();

	//StaticMesh->OnComponentHit.AddDynamic(this, &ATNTCrate::OnHit);
}



void ATNTCrate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATNTCrate::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->GetName().Contains("ThirdPersonCharacter") && (bIsDimensionActive && bIsFirstDimension == Player->bIsFirstDimension) || !bIsDimensionActive)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hit Normal Z: %f"), Hit.Normal.Z);
		if (Hit.Normal.Z == -1.f&&!isHit)
		{
			Cast<ACrashBandicootCharacter>(OtherActor)->LaunchCharacter(LaunchVelocity, false, true);
			isHit = true;
			
			
			GetWorldTimerManager().SetTimer(BombTimerHandle, this, &ATNTCrate::MyDestroy, 3.0f, false, 3.0f);

			BombTriggeredDelegate.Broadcast(BombTimerHandle);
		}

	}
}

void ATNTCrate::MyDestroy()
{
	Destroy();
}
