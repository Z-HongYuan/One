// Copyright © 2025 鸿源z 保留所有权利

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "OneAbilitySystemComponentBase.generated.h"

/*
 * 自定义的AbilitySystemComponent
 */

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ONE_API UOneAbilitySystemComponentBase : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UOneAbilitySystemComponentBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
