// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Kismet/KismetSystemLibrary.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ClimbingCharacter.generated.h"


UCLASS()
class CLIMBINGTEST_API AClimbingCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AClimbingCharacter();


	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FVector CurrentDestination;

	UPROPERTY(EditAnywhere)
	FTimerHandle MoveHandle;

	UFUNCTION(BlueprintNativeEvent)
	void PlayerMoveTo();
	virtual void PlayerMoveTo_Implementation();

	UPROPERTY(EditAnywhere)
	bool IsClimbing;

	UPROPERTY(EditAnywhere)
	float Velocity;

	UPROPERTY(EditAnywhere)
	float RotationValue;

	UPROPERTY(EditAnywhere)
	float RotationSensibility;

	UFUNCTION(BlueprintCallable)
	void ClimbingLineTrace();

	UFUNCTION(BlueprintCallable)
	void CustomEventMove();

	

	FVector GetDirectionUnit(FVector From, FVector To);

protected:
	virtual void BeginPlay() override;

private:	
};
