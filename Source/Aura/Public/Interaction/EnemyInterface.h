// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AURA_API IEnemyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//virtual void HighlightActor() = 0; 0을 놓는것 => pure virtual function => 여기 class에서는 정의하지 않는다는 뜻
	 
	virtual void HighlightActor()=0;
	virtual void UnHighlightActor()=0;
};
