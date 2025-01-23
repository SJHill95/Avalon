// Sam Hill All Rights Reserved


#include "AvalonTypes/AvalonStructTypes.h"
#include "AbilitySystem/Abilities/AvalonHeroGameplayAbility.h"

bool FAvalonHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant != nullptr;
}
