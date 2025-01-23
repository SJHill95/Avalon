// Sam Hill All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/AvalonGameplayAbility.h"
#include "AvalonHeroGameplayAbility.generated.h"

class UHeroCombatComponent;
class AAvalonHeroController;
class AAvalonHeroCharacter;
/**
 * 
 */
UCLASS()
class AVALON_API UAvalonHeroGameplayAbility : public UAvalonGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Avalon|Ability")
	AAvalonHeroCharacter* GetHeroCharacterFromActorInfo();
	
	UFUNCTION(BlueprintPure, Category = "Avalon|Ability")
	AAvalonHeroController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Avalon|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Avalon|Ability")
	FGameplayEffectSpecHandle MakeHeroDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, float InWeaponBaseDamage, FGameplayTag InCurrentAttackTypeTag, int32 InCurrentComboCount);
	
private:
	TWeakObjectPtr<AAvalonHeroCharacter> CachedAvalonHeroCharacter;
	TWeakObjectPtr<AAvalonHeroController> CachedAvalonHeroController;
};
