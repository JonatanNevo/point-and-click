// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "LocationPawn.generated.h"

class UCameraComponent;
class ALocationPawn;

UENUM(BlueprintType)
enum class ELocationDirection : uint8
{
	Forward,
	Backward,
	Left,
	Right,
	ForwardRight,
	ForwardLeft,
	BackwardRight,
	BackwardLeft,
	Other
};

USTRUCT(BlueprintType)
struct FConnectedLocation
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Location")
	ALocationPawn* Location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Location")
	ELocationDirection Direction;
};

UCLASS()
class VERMIS_API ALocationPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ALocationPawn();

	UFUNCTION(BlueprintCallable, Category = "Location")
	void MoveToDirection(ELocationDirection DirectionToMove);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Location")
	UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Location")
	TArray<FConnectedLocation> ConnectedLocations;
};
