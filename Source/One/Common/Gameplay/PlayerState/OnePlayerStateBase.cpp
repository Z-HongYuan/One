// Copyright © 2025 鸿源z 保留所有权利


#include "OnePlayerStateBase.h"

AOnePlayerStateBase::AOnePlayerStateBase()
{
	bReplicates = true; //设置复制
	SetNetUpdateFrequency(200.f); //设置网络同步速度
	SetMinNetUpdateFrequency(100.f); //设置网络同步速度

	AbilitySystemComponent = CreateDefaultSubobject<UOneAbilitySystemComponentBase>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true); //启动复制
	AttributeSet = CreateDefaultSubobject<UOneAttributeSetBase>(TEXT("AttributeSet"));
}
