// Fill out your copyright notice in the Description page of Project Settings.


#include "LocationPawn.h"

#include "Camera/CameraComponent.h"


// Sets default values
ALocationPawn::ALocationPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
}

void ALocationPawn::MoveToDirection(const ELocationDirection DirectionToMove)
{
	for (auto& [Location, Direction] : ConnectedLocations)
	{
		if (Direction == DirectionToMove)
		{
			if(Cast<ALocationPawn>(Location))
			{
				if (const auto PlayerController = Cast<APlayerController>(GetController()))
				{
					PlayerController->UnPossess();
					PlayerController->Possess(Location);
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Location is not a LocationPawn"));
			}
		}
	}
}

// Called when the game starts or when spawned
void ALocationPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALocationPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ALocationPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

