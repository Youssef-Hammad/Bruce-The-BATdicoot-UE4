// Fill out your copyright notice in the Description page of Project Settings.


#include "NitroCrate.h"

void ANitroCrate::BeginPlay()
{
	Super::BeginPlay();

	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &ANitroCrate::OnBeginOverlap);
}

void ANitroCrate::OnBeginOverlap(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FString Name =  OtherActor->GetName();
	if (Name.Contains("ThirdPersonCharacter") || Name.Contains("SpinAttack"))
		Destroy();
}