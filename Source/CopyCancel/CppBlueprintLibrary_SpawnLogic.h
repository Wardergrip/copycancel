// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CppBlueprintLibrary_SpawnLogic.generated.h"

/**
 * 
 */
UCLASS()
class COPYCANCEL_API UCppBlueprintLibrary_SpawnLogic : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AActor> ActorType;

	void SpawnLogic(int maxTreshold,int maxAmountOfActiveEnemies, int amountToSpawn, bool useSpawnVolume);
};
