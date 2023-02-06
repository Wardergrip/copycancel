// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "CppDecorator_FindMinionOrPlayer.generated.h"

/**
 * 
 */
UCLASS()
class COPYCANCEL_API UCppDecorator_FindMinionOrPlayer : public UBTDecorator
{
	GENERATED_BODY()

	UCppDecorator_FindMinionOrPlayer(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// For some reason necessary
	virtual void OnGameplayTaskActivated(UGameplayTask& task) override;
	virtual void OnGameplayTaskDeactivated(UGameplayTask& task) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<AActor> myBPClass;

	/*
	/* Calculates raw, core value of decorator's condition. Should not include calling IsInversed
	*/
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
