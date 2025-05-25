// Copyright © 2025 鸿源z 保留所有权利


#include "OneCharacterBase.h"
#include "One/Common/Gameplay/Component/OneCharacterMovementComponent.h"


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

void AOneCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AOneCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
