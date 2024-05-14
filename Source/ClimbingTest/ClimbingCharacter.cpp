// Fill out your copyright notice in the Description page of Project Settings.


#include "ClimbingCharacter.h"

// Sets default values
AClimbingCharacter::AClimbingCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
    IsClimbing = false;
    //MoveHandle = this -> CreateTimerHandle();
}

// Called when the game starts or when spawned
void AClimbingCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AClimbingCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AClimbingCharacter::ClimbingLineTrace()
{
    // Obtenha a localização do ator
    FVector Start = GetActorLocation();

    // Obtenha a direção para a frente do ator
    FVector ForwardVector = GetActorForwardVector();

    // Defina o comprimento da linha de rastreamento
    float TraceLength = 100.0f;

    // Calcule o ponto final da linha de rastreamento
    FVector End = Start + ForwardVector * TraceLength;

    // Configurar os parâmetros de rastreamento
    FHitResult HitResult;
    FCollisionQueryParams TraceParams(FName(TEXT("ClimbingLineTrace")), false, this);

    bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, TraceParams);
    
    if (bHit)
    {
        DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 5.0f);
        if (CurrentDestination.Z < GetActorLocation().Z) 
        {
            IsClimbing = true;            
        }
    }
    else
    {
        DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 5.0f);
    }
}

void AClimbingCharacter::CustomEventMove()
{
    UKismetSystemLibrary::K2_SetTimer(this, "PlayerMoveTo", 0.01f, true);
    UE_LOG(LogTemp, Warning, TEXT("Caete"));
}

FVector AClimbingCharacter::GetDirectionUnit(FVector From, FVector To)
{
    return (To - From).GetSafeNormal();
}


void AClimbingCharacter::PlayerMoveTo_Implementation()
{
    UE_LOG(LogTemp, Warning, TEXT("Caete"));
}

