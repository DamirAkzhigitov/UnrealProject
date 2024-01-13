// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFirstButton.h"

// Sets default values
AMyFirstButton::AMyFirstButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	_BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	_BoxComponent->SetupAttachment(RootComponent);
	_MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>ButtonMeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/FirstPerson/Maps/ButtonMesh.ButtonMesh'"));
	_MeshComponent->SetStaticMesh(ButtonMeshAsset.Object);
	_MeshComponent->SetupAttachment(_BoxComponent);
}

// Called when the game starts or when spawned
void AMyFirstButton::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyFirstButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AMyFirstButton::IsPressed() {
	return _ButtonPressed;
}

void AMyFirstButton::PressButton() {
	_ButtonPressed = !_ButtonPressed;
}
