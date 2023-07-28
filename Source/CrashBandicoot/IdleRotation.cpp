// Fill out your copyright notice in the Description page of Project Settings.


#include "IdleRotation.h"
#include <Components/StaticMeshComponent.h>
#include <Components/BoxComponent.h>
#include <Kismet/GameplayStatics.h>
#include <Components/SceneComponent.h>

// Sets default values
AIdleRotation::AIdleRotation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	RootComponent = RootComp;

	SM1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM1"));
	SM2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM2"));
	SM3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM3"));
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

	SM1->SetupAttachment(RootComponent);
	SM2->SetupAttachment(RootComponent);
	SM3->SetupAttachment(RootComponent);
	BoxCollision->SetupAttachment(RootComponent);
	RotationRate = 4.0f;
}

// Called when the game starts or when spawned
void AIdleRotation::BeginPlay()
{
	Super::BeginPlay();

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AIdleRotation::OnBeginOverlap);
	
}

// Called every frame
void AIdleRotation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator newRotation = RootComponent->GetComponentRotation();
	newRotation.Yaw += RotationRate;
	RootComponent->SetWorldRotation(newRotation);

}

void AIdleRotation::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->GetName().Contains("ThirdPersonCharacter"))
		UE_LOG(LogTemp, Warning, TEXT("YOU WIN!!"));
}

