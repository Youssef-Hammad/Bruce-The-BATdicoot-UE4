// Fill out your copyright notice in the Description page of Project Settings.


#include "SpinAttack.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASpinAttack::ASpinAttack()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = RootComp;
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SphereCollision->SetupAttachment(RootComp);

	SphereCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	SphereCollision->SetSphereRadius(80.f);

	this->InitialLifeSpan = .5f;

	BaseDamage = 1.f;



}

// Called when the game starts or when spawned
void ASpinAttack::BeginPlay()
{
	Super::BeginPlay();

	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ASpinAttack::OnBeginOverlap);
	
}

// Called every frame
void ASpinAttack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpinAttack::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("OverlappedComp: %s\tOtherActor: %s\tOtherComp: %s"),*OverlappedComp->GetName(),*OtherActor->GetName(),*OtherComp->GetName());
	//if(OtherActor->GetName.Contains())
	UGameplayStatics::ApplyDamage(OtherActor, BaseDamage, UGameplayStatics::GetPlayerController(GetWorld(), 0), UGameplayStatics::GetPlayerPawn(GetWorld(), 0), TSubclassOf<UDamageType>());
}

