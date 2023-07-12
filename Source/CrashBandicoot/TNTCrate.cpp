// Fill out your copyright notice in the Description page of Project Settings.


#include "TNTCrate.h"
#include "CrashBandicootCharacter.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ExplosionActor.h"


ATNTCrate::ATNTCrate()
{
	isHit = false;
	LaunchVelocity = FVector(0, 0, 600);

}

void ATNTCrate::BeginPlay()
{
	Super::BeginPlay();

	StaticMesh->OnComponentHit.AddDynamic(this, &ATNTCrate::OnHit);
}

void ATNTCrate::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->GetName().Contains("ThirdPersonCharacter"))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hit Normal Z: %f"), Hit.Normal.Z);
		if (Hit.Normal.Z < -.001f&&!isHit)
		{
			Cast<ACrashBandicootCharacter>(OtherActor)->LaunchCharacter(LaunchVelocity, false, true);
			isHit = true;
			
		}

	}
}
