// Fill out your copyright notice in the Description page of Project Settings.



#include "Crate.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "CrashBandicootCharacter.h"

// Sets default values
ACrate::ACrate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = RootComp;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComp);

	bIsDimensionActive = false;

	bIsFirstDimension = true;
}

// Called when the game starts or when spawned
void ACrate::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<ACrashBandicootCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (Player == NULL)
		UE_LOG(LogTemp, Error, TEXT("Failed to cast player in Crate.cpp"));
}

// Called every frame
void ACrate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsDimensionActive)
	{
		if (bIsFirstDimension != Player->bIsFirstDimension)
		{
			this->SetActorHiddenInGame(true);
			StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			//StaticMesh->SetSimulatePhysics(false);
		}
		else
		{
			this->SetActorHiddenInGame(false);
			StaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			//StaticMesh->SetSimulatePhysics(true);
		}
	}
	else
	{
		this->SetActorHiddenInGame(false);
		StaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		///StaticMesh->SetSimulatePhysics(true);
	}

}

float ACrate::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if ((bIsDimensionActive && bIsFirstDimension == Player->bIsFirstDimension) || !bIsDimensionActive)
	{
		UE_LOG(LogTemp, Warning, TEXT("Damage Applied to Crate"));
		Destroy();
	}
	return 0.f;
}

