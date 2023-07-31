// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathVolume.h"
#include <Components/BoxComponent.h>
#include <Kismet/GameplayStatics.h>

// Sets default values
ADeathVolume::ADeathVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));

}

// Called when the game starts or when spawned
void ADeathVolume::BeginPlay()
{
	Super::BeginPlay();

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ADeathVolume::OnBeginOverlap);
	
}

// Called every frame
void ADeathVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADeathVolume::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->GetName().Contains("ThirdPersonCharacter"))
		UGameplayStatics::ApplyDamage(OtherActor, 1.f, nullptr, nullptr, nullptr);
}

