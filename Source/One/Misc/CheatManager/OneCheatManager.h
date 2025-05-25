// Copyright © 2025 鸿源z 保留所有权利

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "OneCheatManager.generated.h"

/**
 * 作弊管理器
 * 用于在控制台快速执行蓝图函数/命令\n
 * 比如 在控制台输入 "SetPlayerHealth 5000" 可以执行 当前SetPlayerHealth(5000)函数\n
 */
UCLASS()
class ONE_API UOneCheatManager : public UCheatManager
{
	GENERATED_BODY()

public:
};
