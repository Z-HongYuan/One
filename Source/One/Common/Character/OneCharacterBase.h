// Copyright © 2025 鸿源z 保留所有权利

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "One/Common/AbilitySystem/OneAbilitySystemComponentBase.h"
#include "One/Common/AbilitySystem/Attribute/OneAttributeSetBase.h"
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
	/*--------------------拥有的组件-------------------------------------------*/

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"), Category="Character")
	//Copy的Character的Mesh
	TObjectPtr<USkeletalMeshComponent> CoverMesh;
	/*----------------------------------------------------------------------------------*/

	/*----------------------AbilitySystem相关--------------------------------*/
	UPROPERTY()
	TObjectPtr<UOneAbilitySystemComponentBase> AbilitySystemComponent;
	UPROPERTY()
	TObjectPtr<UOneAttributeSetBase> AttributeSet;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
