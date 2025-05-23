// Copyright longlt00502@gmail.com 2023. All rights reserved.
#pragma once
#if ENGINE_MAJOR_VERSION == 5
#if ENGINE_MINOR_VERSION <= 2
#include "IKRigSolver.h"
#else
#include "Rig/Solvers/IKRigSolver.h"
#endif
#endif
#include "FreeBoneSnapper.h"
#include "IKRig_BoneSnapperSolver.generated.h"
UENUM(BlueprintType)
enum class ESnapMode : uint8 {
    Translation,
    Rotation,
    Scale,
};
UCLASS(BlueprintType)
class UIKRig_FBoneSnapperSettings : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Settings")
	FName SourceBone = NAME_None;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	FName DestinationBone = NAME_None;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (Bitmask, BitmaskEnum="/Script/FreeBoneSnapper.ESnapMode"))
	uint8 SnapMode = 7u;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	FTransform Offset;
	inline bool IsSet(ESnapMode Mode) const
	{
		return (SnapMode & (1u << StaticCast<uint8>(Mode))) != 0;
	}
#if WITH_EDITOR
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	class UIKRig_BoneSnapperSolver *Solver;
#endif
};
UCLASS(BlueprintType, EditInlineNew, config = Engine, hidecategories = UObject)
class UIKRig_BoneSnapperSolver : public UIKRigSolver
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Root")
	FName RootSnapBoneName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Root")
	bool InPlace = false;
	UPROPERTY()
	TArray<TObjectPtr<UIKRig_FBoneSnapperSettings>> BoneSettings;
	void Initialize(const FIKRigSkeleton& IKRigSkeleton) override;
	void Solve(FIKRigSkeleton& IKRigSkeleton, const FIKRigGoalContainer& Goals) override;
	void RemoveGoal(const FName& GoalName) override {}
	inline FName GetRootBone() const override { return RootSnapBoneName; };
#if WITH_EDITOR
	void AddGoal(const UIKRigEffectorGoal& NewGoal) override {}
	void RenameGoal(const FName& OldName, const FName& NewName) override {}
	void SetGoalBone(const FName& GoalName, const FName& NewBoneName) override {}
	FText GetNiceName() const override;
	bool IsBoneAffectedBySolver(const FName& BoneName, const FIKRigSkeleton& IKRigSkeleton) const override;
	bool GetWarningMessage(FText& OutWarningMessage) const override;
	inline void SetRootBone(const FName& RootBoneName) override
	{
		RootSnapBoneName = RootBoneName;
	}
	inline bool RequiresRootBone() const override { return true; };
	void AddBoneSetting(const FName& BoneName) override;
	void RemoveBoneSetting(const FName& BoneName) override;
	UObject* GetBoneSetting(const FName& BoneName) const override;
	bool UsesBoneSettings() const override{ return true;};
#endif
private:
	TArray<int32> BoneDepths;
	bool Dirty=true;
	friend class UIKRig_FBoneSnapperSettings;
};
