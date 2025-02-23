// Sam Hill All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AvalonTypes/AvalonEnumTypes.h"
#include "AvalonGameplayAbility.generated.h"

class UAvalonAbilitySystemComponent;
class UPawnCombatComponent;

UENUM(BlueprintType)
enum class EAvalonAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};

/**
 * 
 */
UCLASS()
class AVALON_API UAvalonGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	//~ Begin UGameplayAbility Interface.
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~ End UGameplayAbility Interface.
	
	UPROPERTY(EditDefaultsOnly, Category = "Avalon|Ability")
	EAvalonAbilityActivationPolicy AbilityActivationPolicy = EAvalonAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category = "Avalon|Ability")
	UPawnCombatComponent* GetPawnCombatComponentFromActorInfo() const;

	UFUNCTION(BlueprintPure, Category = "Avalon|Ability")
	UAvalonAbilitySystemComponent* GetAvalonAbilitySystemComponentFromActorInfo() const;

	FActiveGameplayEffectHandle NativeApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle InSpecHandle);

	UFUNCTION(BlueprintCallable, Category = "Avalon|Ability", meta = (DisplayName = "Apply Gameplay Effect Spec Handle to Target Actor" ,ExpandEnumAsExecs = "OutSuccessType"))
	FActiveGameplayEffectHandle BP_ApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle InSpecHandle, EAvalonSuccessType& OutSuccessType);
};
