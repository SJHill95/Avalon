// Sam Hill All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartupData/DataAsset_StartupDataBase.h"
#include "DataAsset_EnemyStartupData.generated.h"

class UAvalonEnemyGameplayAbility;

/**
 * 
 */
UCLASS()
class AVALON_API UDataAsset_EnemyStartupData : public UDataAsset_StartupDataBase
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UAvalonAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "StartupData")
	TArray<TSubclassOf<UAvalonEnemyGameplayAbility>> EnemyCombatAbilities;
	
};
