// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include <Components/StaticMeshComponent.h>
#include <Components/BoxComponent.h>

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	RootComponent = StaticMesh;
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	isMovingToB = true;

	SetActorLocation(PointA);
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
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

