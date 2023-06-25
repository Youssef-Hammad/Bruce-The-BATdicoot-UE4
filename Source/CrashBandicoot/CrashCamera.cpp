// Fill out your copyright notice in the Description page of Project Settings.


#include "CrashCamera.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SplineComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ACrashCamera::ACrashCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultScene"));
	SetRootComponent(DefaultRoot);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Boom"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 250.f;
	SpringArm->bUsePawnControlRotation = false;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow Camera"));
	FollowCamera->SetupAttachment(SpringArm);
	FollowCamera->bUsePawnControlRotation = false;

	Spline = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	Spline->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ACrashCamera::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* CrashController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	CrashController->SetViewTargetWithBlend(this);
	
	Crash = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
}

// Called every frame
void ACrashCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector vec_NewLocation = Spline->FindLocationClosestToWorldLocation(Crash->GetActorLocation(), ESplineCoordinateSpace::World);
	FRotator rot_NewRotation = UKismetMathLibrary::MakeRotFromX(Spline->FindDirectionClosestToWorldLocation(Crash->GetActorLocation(), ESplineCoordinateSpace::World));

	rot_NewRotation.Pitch = Pitch_Offset;
	rot_NewRotation.Roll = 0;
	SpringArm->SetWorldLocation(vec_NewLocation);

	UE_LOG(LogTemp, Warning, TEXT("New Rotation: Roll: %f   Pitch: %f  Yaw: %f\n"), rot_NewRotation.Roll, rot_NewRotation.Pitch, rot_NewRotation.Yaw);

	SpringArm->SetWorldRotation(rot_NewRotation);

}

