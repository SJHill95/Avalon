// Sam Hill All Rights Reserved


#include "DataAssets/StartupData/DataAsset_StartupDataBase.h"

#include "AbilitySystem/AvalonAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/AvalonGameplayAbility.h"

void UDataAsset_StartupDataBase::GiveToAbilitySystemComponent(UAvalonAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	check(InASCToGive != NULL);

	GrantAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);

	if (!StartupGameplayEffects.IsEmpty())
	{
		for (const TSubclassOf<UGameplayEffect>& EffectsClass: StartupGameplayEffects)
		{
			if (!EffectsClass) continue;

			UGameplayEffect* EffectCDO = EffectsClass->GetDefaultObject<UGameplayEffect>();
			InASCToGive->ApplyGameplayEffectToSelf(EffectCDO, ApplyLevel, InASCToGive->MakeEffectContext());
		}
	}
	
}

void UDataAsset_StartupDataBase::GrantAbilities(const TArray<TSubclassOf<UAvalonGameplayAbility>>& InAbilitiesToGive,
	UAvalonAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for (const TSubclassOf<UAvalonGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		
		InASCToGive->GiveAbility(AbilitySpec);
	}
}
