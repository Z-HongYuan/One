// Copyright © 2025 鸿源z 保留所有权利


#include "OneCharacterBase.h"


AOneCharacterBase::AOneCharacterBase(const class FObjectInitializer& ObjectInitializer):
	Super(ObjectInitializer.SetDefaultSubobjectClass<UOneCharacterMovementComponent>(CharacterMovementComponentName))

{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true; //启动复制

	GetMesh()->bPropagateCurvesToFollowers = true; // 曲线同步到子Mesh
	GetMesh()->SetCollisionProfileName("NoCollision"); //无碰撞
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision); //无碰撞
	GetMesh()->CastShadow = false; //不投射阴影
	GetMesh()->SetVisibleFlag(false); //不可见
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
	//总是刷新动画和骨骼

	CoverMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CoverMesh")); //创建CoverMesh
	CoverMesh->SetupAttachment(GetMesh()); //附加到原本的Mesh上
	CoverMesh->SetRenderCustomDepth(true); //启用自定义深度渲染
}

void AOneCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void AOneCharacterBase::InitAbilitySystemComponent()
{
	//父类中不做任何事情,将会在子类中实现
}

void AOneCharacterBase::InitAttributeSet() const
{
	if (GetAbilitySystemComponent() and StartupAttribute)
	{
		GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*GetAbilitySystemComponent()->MakeOutgoingSpec(
			                                                             StartupAttribute,
			                                                             -1,
			                                                             GetAbilitySystemComponent()->MakeEffectContext()
		                                                             ).Data.Get(), GetAbilitySystemComponent());
	}
}

void AOneCharacterBase::InitStartAbilitiesAndEffects()
{
	//开始时的GE
	for (TSubclassOf<UGameplayEffect>& Effect : StartupEffects)
	{
		if (!Effect) continue;
		FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
		FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(Effect, -1, ContextHandle);
		GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
	}

	//服务端Give
	if (HasAuthority())
	{
		for (TSubclassOf<UGameplayAbility>& Ability : StartupAbilities)
		{
			if (!Ability) continue;
			FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability, -1, -1, this);
			GetAbilitySystemComponent()->GiveAbilityWithTag(AbilitySpec);
		}
	}

	//服务端Give
	if (HasAuthority())
	{
		for (TSubclassOf<UGameplayAbility>& Ability : StartupDoOnceAbilities)
		{
			if (!Ability) continue;
			FGameplayAbilitySpec AbilitySpec(Ability, -1, -1, this);
			GetAbilitySystemComponent()->GiveAbilityAndActivateOnce(AbilitySpec);
		}
	}
}

void AOneCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AOneCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
