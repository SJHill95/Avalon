// Sam Hill All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/AvalonGameplayAbility.h"
#include "AvalonEnemyGameplayAbility.generated.h"

class UEnemyCombatComponent;
class AAvalonEnemyCharacter;
/**
 * 
 */
UCLASS()
class AVALON_API UAvalonEnemyGameplayAbility : public UAvalonGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Avalon|Ability")
	AAvalonEnemyCharacter* GetEnemyCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Avalon|Ability")
	UEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<AAvalonEnemyCharacter> CachedAvalonEnemyCharacter;
};
