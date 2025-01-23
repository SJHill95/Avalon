// Sam Hill All Rights Reserved


#include "Components/Combat/HeroCombatComponent.h"
#include "Items/Weapons/AvalonHeroWeapon.h"
#include "AvalonDebugHelper.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AvalonGameplayTags.h"

AAvalonHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AAvalonHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}

void UHeroCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor))
	{
		return;
	}

	OverlappedActors.AddUnique(HitActor);

	FGameplayEventData Data;
	Data.Instigator = GetOwningPawn();
	Data.Target = HitActor;
	
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningPawn(), AvalonGameplayTags::Shared_Event_MeleeHit, Data);
	}

void UHeroCombatComponent::OnWeaponPulledFromTargetActor(AActor* InteractedActor)
{
	Debug::Print(GetOwningPawn()->GetActorNameOrLabel() + TEXT(" pulled from ") + InteractedActor->GetActorNameOrLabel(), FColor::Red);
}
