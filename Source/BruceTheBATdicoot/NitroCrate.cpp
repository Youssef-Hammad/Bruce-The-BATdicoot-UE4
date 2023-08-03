// Fill out your copyright notice in the Description page of Project Settings.


#include "NitroCrate.h"
#include "CrashBandicootCharacter.h"

void ANitroCrate::BeginPlay()
{
	Super::BeginPlay();

	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &ANitroCrate::OnBeginOverlap);
}

void ANitroCrate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANitroCrate::OnBeginOverlap(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FString Name =  OtherActor->GetName();
	if ((bIsDimensionActive && bIsFirstDimension == Player->bIsFirstDimension) || !bIsDimensionActive && Name.Contains("ThirdPersonCharacter") || Name.Contains("SpinAttack"))
		Destroy();
}