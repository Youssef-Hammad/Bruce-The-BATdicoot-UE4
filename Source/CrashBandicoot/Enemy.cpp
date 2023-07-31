// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Components/CapsuleComponent.h"
#include <Kismet/GameplayStatics.h>
#include "CrashBandicootCharacter.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	isMovingToB = true;

	SetActorLocation(PointA);

	//GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnBeginOverlap);
	GetMesh()->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnBeginOverlap);
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (isMovingToB)
	{
		this->SetActorLocation(FMath::VInterpConstantTo(GetActorLocation(), PointB, DeltaTime, MovementSpeed));
	}
	else
	{
		this->SetActorLocation(FMath::VInterpConstantTo(GetActorLocation(), PointA, DeltaTime, MovementSpeed));
	}

	FVector CurrentLocation = GetActorLocation();

	if (CurrentLocation.X == PointB.X && CurrentLocation.Y == PointB.Y && isMovingToB)
		isMovingToB = false;
	if (CurrentLocation.X == PointA.X && CurrentLocation.Y == PointA.Y && !isMovingToB)
		isMovingToB = true;

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("OtherActor: %s"), *OtherActor->GetName());
	if (OtherActor->GetName().Contains("ThirdPersonCharacter"))
	{
		if(Cast<ACrashBandicootCharacter>(OtherActor)->bIsSpinning)
			Destroy();
		else
			UGameplayStatics::ApplyDamage(OtherActor, 1.f, nullptr, this, nullptr);
		//UE_LOG(LogTemp, Warning, TEXT("Killed"));
		//OtherActor->Destroy();
		//FGenericPlatformMisc::RequestExit(false);
	}
		
}

