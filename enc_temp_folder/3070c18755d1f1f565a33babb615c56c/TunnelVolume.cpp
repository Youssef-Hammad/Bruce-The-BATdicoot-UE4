// Fill out your copyright notice in the Description page of Project Settings.


#include "TunnelVolume.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TunnelCamModifier.h"

// Sets default values
ATunnelVolume::ATunnelVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root Comp"));
	SetRootComponent(RootComp);
	BoxCollision->SetupAttachment(RootComp);

}

// Called when the game starts or when spawned
void ATunnelVolume::BeginPlay()
{
	Super::BeginPlay();

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ATunnelVolume::OnBoxBeginOverlap);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &ATunnelVolume::OnBoxEndOverlap);
	
}

// Called every frame
void ATunnelVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATunnelVolume::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("Begin OtherActor: %s"), *OtherActor->GetName());
	if (OtherActor->GetName().Contains("ThirdPersonCharacter"))
	{
		TSubclassOf<UTunnelCamModifier> CameraModifier = UTunnelCamModifier::StaticClass();
		CamModifier = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->AddNewCameraModifier(CameraModifier);
	}
}

void ATunnelVolume::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("End OtherActor: %s"), *OtherActor->GetName());
	if(OtherActor->GetName().Contains("ThirdPersonCharacter"))
		UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->RemoveCameraModifier(CamModifier);
}

