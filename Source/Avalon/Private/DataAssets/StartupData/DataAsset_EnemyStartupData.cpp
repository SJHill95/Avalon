// Sam Hill All Rights Reserved


#include "DataAssets/StartupData/DataAsset_EnemyStartupData.h"

#include "AbilitySystem/AvalonAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/AvalonEnemyGameplayAbility.h"

void UDataAsset_EnemyStartupData::GiveToAbilitySystemComponent(UAvalonAbilitySystemComponent* InASCToGive,
                                                               int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	if (!EnemyCombatAbilities.IsEmpty())
	{
		for (const TSubclassOf<UAvalonEnemyGameplayAbility>& AbilityClass : EnemyCombatAbilities)
		{
			if (AbilityClass == nullptr) continue;

			FGameplayAbilitySpec AbilitySpec(AbilityClass);
			AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
			AbilitySpec.Level = ApplyLevel;

			InASCToGive->GiveAbility(AbilitySpec);
		}
	}
}
