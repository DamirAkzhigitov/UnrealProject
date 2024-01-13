// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "MyFirstButton.generated.h"

UCLASS()
class MYPROJECT3_API AMyFirstButton : public AActor 
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyFirstButton();
	UPROPERTY(EditAnywhere, Category = "My Button")
	bool ButtonPressed = false;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "My Button", meta = (AllowPrivateAccess = "true"));
	UBoxComponent* _BoxComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "My Button", meta = (AllowPrivateAccess = "true"));
	UStaticMeshComponent* _MeshComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool _ButtonPressed;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "My Button", Meta = (DisplayName = "Is Pressed"))
	bool IsPressed();
	UFUNCTION(BlueprintCallable, Category = "My Button", Meta = (DisplayName = "Press Button"))
	void PressButton();
	FORCEINLINE	UBoxComponent* GetBoxComponent() const
	{
		return _BoxComponent;
	}
	FORCEINLINE UStaticMeshComponent* GetMeshComponent() const
	{
		return _MeshComponent;
	}
};
