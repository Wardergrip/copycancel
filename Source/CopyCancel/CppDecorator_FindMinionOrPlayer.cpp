// Fill out your copyright notice in the Description page of Project Settings.


#include "CppDecorator_FindMinionOrPlayer.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

UCppDecorator_FindMinionOrPlayer::UCppDecorator_FindMinionOrPlayer(const FObjectInitializer& ObjectInitializer)
	:UBTDecorator{ObjectInitializer}
{
	bAllowAbortChildNodes = true;
	bAllowAbortLowerPri = true;
	bAllowAbortNone = true;
}

void UCppDecorator_FindMinionOrPlayer::OnGameplayTaskActivated(UGameplayTask& task)
{
}

void UCppDecorator_FindMinionOrPlayer::OnGameplayTaskDeactivated(UGameplayTask& task)
{
}

bool UCppDecorator_FindMinionOrPlayer::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	float shortestRange{ 9999.0f };
	bool foundTarget{ false };
	UObject* closestMinion{ nullptr };

	UBlackboardComponent* myBlackboard = OwnerComp.GetBlackboardComponent();
	FName fname_attackTag{"AttackTag"};
	FName fname_detectionRange{"DetectionRange"};
	FName fname_selfActor{"SelfActor"};
	FName fname_target{ "Target" };
	FName attackTag{ myBlackboard->GetValueAsString(fname_attackTag) };
	float detectionRange = myBlackboard->GetValueAsFloat(fname_detectionRange);
	AActor* selfActor = reinterpret_cast<AActor*>(myBlackboard->GetValueAsObject(fname_selfActor));

	TArray<AActor*> foundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), myBPClass, foundActors);

	for (auto actor : foundActors)
	{
		if (!actor->Tags.Contains(attackTag)) continue;

		float distance = FVector::Distance(actor->GetActorLocation(), selfActor->GetActorLocation());

		if (distance < detectionRange && distance < shortestRange)
		{
			shortestRange = distance;
			closestMinion = actor;
			foundTarget = true;
		}
	}

	if (foundTarget)
	{
		myBlackboard->SetValueAsObject(fname_target,closestMinion);
	}
	else
	{
		FName fname_player{ "Player" };
		UObject* player = myBlackboard->GetValueAsObject(fname_player);
		if (player)
		{
			foundTarget = false;
			myBlackboard->SetValueAsObject(fname_target, player);
		}
	}

	return foundTarget;
}
