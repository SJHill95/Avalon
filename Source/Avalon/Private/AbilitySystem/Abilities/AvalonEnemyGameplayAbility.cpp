// Sam Hill All Rights Reserved


#include "AbilitySystem/Abilities/AvalonEnemyGameplayAbility.h"

#include "Characters/AvalonEnemyCharacter.h"
#include "Components/Combat/EnemyCombatComponent.h"

AAvalonEnemyCharacter* UAvalonEnemyGameplayAbility::GetEnemyCharacterFromActorInfo()
{
	if (!CachedAvalonEnemyCharacter.IsValid())
	{
		CachedAvalonEnemyCharacter = Cast<AAvalonEnemyCharacter>(CurrentActorInfo->AvatarActor);
	}

	return CachedAvalonEnemyCharacter.IsValid() ? CachedAvalonEnemyCharacter.Get() : nullptr;
}

UEnemyCombatComponent* UAvalonEnemyGameplayAbility::GetEnemyCombatComponentFromActorInfo()
{
	return GetEnemyCharacterFromActorInfo()->GetEnemyCombatComponent();
}
