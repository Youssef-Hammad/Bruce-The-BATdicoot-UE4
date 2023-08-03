// Fill out your copyright notice in the Description page of Project Settings.


#include "CrateBounce.h"
#include "CrashBandicootCharacter.h"

void ACrateBounce::BeginPlay()
{
	Super::BeginPlay();
}

ACrateBounce::ACrateBounce()
{
	Hits = 3;
}

void ACrateBounce::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACrateBounce::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->GetName().Contains("ThirdPersonCharacter") && (bIsDimensionActive && bIsFirstDimension == Player->bIsFirstDimension) || !bIsDimensionActive)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hit Normal Z: %f"), Hit.Normal.Z);
		if (Hit.Normal.Z == -1.f || Hit.Normal.Z == 1.f)
		{
			if(Hit.Normal.Z==-1.f)
				Cast<ACrashBandicootCharacter>(OtherActor)->LaunchCharacter(LaunchVelocity, false, true);
			Hits--;
			if(Hits<= 0)
				Destroy();
		}
			
	}
}
