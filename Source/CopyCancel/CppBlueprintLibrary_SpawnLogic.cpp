// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBlueprintLibrary_SpawnLogic.h"
#include "Kismet/GameplayStatics.h"

void UCppBlueprintLibrary_SpawnLogic::SpawnLogic(int maxTreshold, int maxAmountOfActiveEnemies, int amountToSpawn, bool useSpawnVolume)
{
	TArray<AActor*> actors;
	auto world = GetWorld();
	UGameplayStatics::GetAllActorsOfClass(world, ActorType, actors);

	auto amountActors = actors.Num();
	if (amountActors < maxTreshold && amountActors < maxAmountOfActiveEnemies)
	{

		for (size_t i{ 0 }; i < amountToSpawn; ++i)
		{
			//world->SpawnActor(ActorType,)
		}
	}
}
