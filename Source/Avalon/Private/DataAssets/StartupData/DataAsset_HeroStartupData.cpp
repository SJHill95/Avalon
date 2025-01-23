// Sam Hill All Rights Reserved


#include "DataAssets/StartupData/DataAsset_HeroStartupData.h"
#include "AbilitySystem/AvalonAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/AvalonHeroGameplayAbility.h"
#include "AvalonTypes/AvalonStructTypes.h"

void UDataAsset_HeroStartupData::GiveToAbilitySystemComponent(UAvalonAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	for (const FAvalonHeroAbilitySet& AbilitySet : HeroStartupAbilitySets)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilitySet.InputTag);
		
		InASCToGive->GiveAbility(AbilitySpec);
	}
}
