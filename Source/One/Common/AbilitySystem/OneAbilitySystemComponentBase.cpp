// Copyright © 2025 鸿源z 保留所有权利


#include "OneAbilitySystemComponentBase.h"


// Sets default values for this component's properties
UOneAbilitySystemComponentBase::UOneAbilitySystemComponentBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOneAbilitySystemComponentBase::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UOneAbilitySystemComponentBase::TickComponent(float DeltaTime, ELevelTick TickType,
                                                   FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
