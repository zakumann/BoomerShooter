// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PooledObject.h"
#include "ObjectsPool.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BOOMERSHOOTER_API UObjectsPool : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UObjectsPool();

	UFUNCTION(BlueprintCallable, Category = "Objects Pool")
	APooledObject* SpawnPooledObject(FVector SpawnLocation, FRotator SpawnRotation);

	UPROPERTY(EditAnywhere, Category = "Objects Pool")
	TSubclassOf<class APooledObject> PooledObjectSubclass;

	UPROPERTY(EditAnywhere, Category = "Objects Pool")
	int PoolSize = 20;

	UPROPERTY(EditAnywhere, Category = "Objects Pool")
	float PooledObjectLifeSpan = 0.0f;

	UFUNCTION()
	void OnPooledObjectDespawn(APooledObject* PoolActor);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	TArray<APooledObject*> ObjectPool;
	TArray<int> SpawnedPoolIndexes;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
