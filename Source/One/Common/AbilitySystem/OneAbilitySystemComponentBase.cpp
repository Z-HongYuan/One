// Copyright © 2025 鸿源z 保留所有权利


#include "OneAbilitySystemComponentBase.h"

#include "AbilitySystemLog.h"
#include "Ability/OneGameplayAbilityBase.h"


UOneAbilitySystemComponentBase::UOneAbilitySystemComponentBase()
{
	PrimaryComponentTick.bCanEverTick = true;
	// SetIsReplicated(true); //选择设置是否复制
}

FGameplayAbilitySpecHandle UOneAbilitySystemComponentBase::GiveAbilityWithTag(FGameplayAbilitySpec& Spec)
{
	if (const UOneGameplayAbilityBase* GenshinAbility = Cast<UOneGameplayAbilityBase>(Spec.Ability))
	{
		if (GenshinAbility->InputTag.IsValid())
		{
			Spec.GetDynamicSpecSourceTags().AddTag(GenshinAbility->InputTag);
		}
	}
	return GiveAbility(Spec);
}

FGameplayAbilitySpecHandle UOneAbilitySystemComponentBase::K2_GiveAbilityWithTag(
	TSubclassOf<UGameplayAbility> AbilityClass, int32 Level, int32 InputID)
{
	// 构建并验证 Ability Spec
	FGameplayAbilitySpec AbilitySpec = BuildAbilitySpecFromClass(AbilityClass, Level, InputID);

	// 验证类
	if (!IsValid(AbilitySpec.Ability))
	{
		ABILITY_LOG(Error, TEXT("K2_GiveAbility() called with an invalid Ability Class."));

		return FGameplayAbilitySpecHandle();
	}

	// 授予 ability 并返回 handle。这将运行验证和权限检查
	return GiveAbilityWithTag(AbilitySpec);
}

void UOneAbilitySystemComponentBase::AbilityInputTagHeld(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;

	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())	//循环查找并激活包含有对应InputTag的Ability
	{
		if (AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InputTag))
		{
			AbilitySpecInputPressed(AbilitySpec);	//通知Ability内的输入按下
			if (!AbilitySpec.IsActive())
			{
				TryActivateAbility(AbilitySpec.Handle);	//并且如果能力未被激活,就激活一次
			}
		}
	}
}

void UOneAbilitySystemComponentBase::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;

	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())	//循环查找并激活包含有对应InputTag的Ability
	{
		if (AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InputTag))
		{
			AbilitySpecInputReleased(AbilitySpec);	//通知Ability内的输入释放
		}
	}
}


void UOneAbilitySystemComponentBase::BeginPlay()
{
	Super::BeginPlay();

}


void UOneAbilitySystemComponentBase::TickComponent(float DeltaTime, ELevelTick TickType,
                                                   FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}
