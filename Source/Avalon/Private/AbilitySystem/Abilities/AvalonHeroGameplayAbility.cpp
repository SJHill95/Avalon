// Sam Hill All Rights Reserved


#include "AbilitySystem/Abilities/AvalonHeroGameplayAbility.h"

#include "AbilitySystem/AvalonAbilitySystemComponent.h"
#include "Characters/AvalonHeroCharacter.h"
#include "Controllers/AvalonHeroController.h"
#include "AvalonGameplayTags.h"

AAvalonHeroCharacter* UAvalonHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedAvalonHeroCharacter.IsValid())
	{
		CachedAvalonHeroCharacter = Cast<AAvalonHeroCharacter>(CurrentActorInfo->AvatarActor);
	}
	
	return CachedAvalonHeroCharacter.IsValid() ? CachedAvalonHeroCharacter.Get() : nullptr;
}

AAvalonHeroController* UAvalonHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedAvalonHeroController.IsValid())
	{
		CachedAvalonHeroController = Cast<AAvalonHeroController>(CurrentActorInfo->PlayerController);
	}
	
	return CachedAvalonHeroController.IsValid() ? CachedAvalonHeroController.Get() : nullptr;
}

UHeroCombatComponent* UAvalonHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}

FGameplayEffectSpecHandle UAvalonHeroGameplayAbility::MakeHeroDamageEffectSpecHandle(
	TSubclassOf<UGameplayEffect> EffectClass, float InWeaponBaseDamage, FGameplayTag InCurrentAttackTypeTag,
	int32 InCurrentComboCount)
{
	check (EffectClass != nullptr);
	
	FGameplayEffectContextHandle ContextHandle = GetAvalonAbilitySystemComponentFromActorInfo()->MakeEffectContext();
	ContextHandle.SetAbility(this);
	ContextHandle.AddSourceObject(GetAvalonAbilitySystemComponentFromActorInfo());
	ContextHandle.AddInstigator(GetAvatarActorFromActorInfo(), GetAvatarActorFromActorInfo());
	
	 FGameplayEffectSpecHandle EffectSpecHandle = GetAvalonAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(EffectClass, GetAbilityLevel(), ContextHandle);

	EffectSpecHandle.Data->SetSetByCallerMagnitude(AvalonGameplayTags::Shared_SetByCaller_BaseDamage, InWeaponBaseDamage);

	if (InCurrentAttackTypeTag.IsValid())
	{
		EffectSpecHandle.Data->SetSetByCallerMagnitude(InCurrentAttackTypeTag, InCurrentComboCount);
	}

	return EffectSpecHandle;
}
