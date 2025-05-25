// Copyright © 2025 鸿源z 保留所有权利

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "One/Common/AbilitySystem/OneAbilitySystemComponentBase.h"
#include "One/Common/AbilitySystem/Attribute/OneAttributeSetBase.h"
#include "OnePlayerStateBase.generated.h"

/**
 * 
 */
UCLASS()
class ONE_API AOnePlayerStateBase : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AOnePlayerStateBase();

	//返回ASC
	virtual UOneAbilitySystemComponentBase* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }
	//返回AttributeSet
	UOneAttributeSetBase* GetAttributeSet() const { return AttributeSet; }

protected:
	UPROPERTY()
	TObjectPtr<UOneAbilitySystemComponentBase> AbilitySystemComponent;
	UPROPERTY()
	TObjectPtr<UOneAttributeSetBase> AttributeSet;
};
