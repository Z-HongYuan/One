// Copyright © 2025 鸿源z 保留所有权利

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "One/Common/AbilitySystem/OneAbilitySystemComponentBase.h"
#include "One/Common/AbilitySystem/Attribute/OneAttributeSetBase.h"
#include "One/Common/Gameplay/Component/OneCharacterMovementComponent.h"
#include "OneCharacterBase.generated.h"

/**
 *抽象角色基类
 *派生类需要自己创建Create ASC和Attribute
 */

UCLASS(Abstract, Category="Character")
class ONE_API AOneCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AOneCharacterBase(const class FObjectInitializer& ObjectInitializer);

	virtual UOneAbilitySystemComponentBase* GetAbilitySystemComponent() const override
	{
		return AbilitySystemComponent;
	}

	UOneAttributeSetBase* GetAttributeSet() const { return AttributeSet; }

	//获取CoverMesh
	UFUNCTION(BlueprintPure, Category="One")
	USkeletalMeshComponent* GetCoverMesh() const { return CoverMesh; }

protected:
	virtual void BeginPlay() override;

	/*--------------------拥有的组件-------------------------------------------*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"), Category="Character")
	//用于Copy的原动画数据Character的Mesh
	TObjectPtr<USkeletalMeshComponent> CoverMesh;
	/*----------------------------------------------------------------------------------*/

	/*----------------------AbilitySystem相关--------------------------------*/
	UPROPERTY()
	TObjectPtr<UOneAbilitySystemComponentBase> AbilitySystemComponent;
	UPROPERTY()
	TObjectPtr<UOneAttributeSetBase> AttributeSet;

	//初始属性集
	UPROPERTY(EditDefaultsOnly, Category = "AbilitySystem")
	TSubclassOf<UGameplayEffect> StartupAttribute;

	//初始GE效果
	UPROPERTY(EditDefaultsOnly, Category = "AbilitySystem")
	TArray<TSubclassOf<UGameplayEffect>> StartupEffects;

	//初始能力
	UPROPERTY(EditDefaultsOnly, Category = "AbilitySystem")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

	//初始能力并且执行一次
	UPROPERTY(EditDefaultsOnly, Category = "AbilitySystem")
	TArray<TSubclassOf<UGameplayAbility>> StartupDoOnceAbilities;

	//初始化AbilitySystemComponent,不做任何事,将在子类中实现
	virtual void InitAbilitySystemComponent();
	void InitAttributeSet() const;	//必须调用,全部Give的Level=-1,使用GE初始化AttributeSet
	void InitStartAbilitiesAndEffects();	//必须调用,全部Give的Level=-1
	/*--------------------------------------------------------------------------*/
	
public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
