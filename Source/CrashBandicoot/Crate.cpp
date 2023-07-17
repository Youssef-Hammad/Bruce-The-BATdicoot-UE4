// Fill out your copyright notice in the Description page of Project Settings.



#include "Crate.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACrate::ACrate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = RootComp;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComp);


}

// Called when the game starts or when spawned
void ACrate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACrate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ACrate::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	UE_LOG(LogTemp, Warning, TEXT("Damage Applied to Crate"));
	Destroy();
	return 0.f;
}

