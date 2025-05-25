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
	UOneAbilitySystemComponentBase();

	// 对传入的Spec添加InputTag后给予技能,这并不是安全的, 因为Spec不是const,需要修改Ability
	FGameplayAbilitySpecHandle GiveAbilityWithTag(FGameplayAbilitySpec& Spec);

	// 对传入的Spec添加InputTag后给予技能,蓝图方法
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "Gameplay Abilities",
		meta = (DisplayName = "Give Ability With Tag", ScriptName = "GiveAbilityWithTag"))
	FGameplayAbilitySpecHandle K2_GiveAbilityWithTag(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level = 0,
	                                                 int32 InputID = -1);

	//从输入调用触发技能的函数
	UFUNCTION(BlueprintCallable, Category = "Gameplay Abilities")
	void AbilityInputTagHeld(const FGameplayTag& InputTag);
	UFUNCTION(BlueprintCallable, Category = "Gameplay Abilities")
	void AbilityInputTagReleased(const FGameplayTag& InputTag);

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
