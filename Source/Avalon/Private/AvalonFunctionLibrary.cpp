// Sam Hill All Rights Reserved


#include "AvalonFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/AvalonAbilitySystemComponent.h"
#include "Interfaces/PawnCombatInterface.h"

UAvalonAbilitySystemComponent* UAvalonFunctionLibrary::NativeGetAvalonASCFromActor(AActor* InActor)
{
	check(InActor != nullptr);

	return Cast<UAvalonAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UAvalonFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	UAvalonAbilitySystemComponent* ASC = NativeGetAvalonASCFromActor(InActor);

	if (!ASC->HasMatchingGameplayTag(TagToAdd))
	{
		ASC->AddLooseGameplayTag(TagToAdd);
	}
}

void UAvalonFunctionLibrary::RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
	UAvalonAbilitySystemComponent* ASC = NativeGetAvalonASCFromActor(InActor);

	if (ASC->HasMatchingGameplayTag(TagToRemove))
	{
		ASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool UAvalonFunctionLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
	UAvalonAbilitySystemComponent* ASC = NativeGetAvalonASCFromActor(InActor);

	return ASC->HasMatchingGameplayTag(TagToCheck);
}

void UAvalonFunctionLibrary::BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck,
	EAvalonConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoesActorHaveTag(InActor, TagToCheck) ? EAvalonConfirmType::Yes : EAvalonConfirmType::No;
}

UPawnCombatComponent* UAvalonFunctionLibrary::NativeGetPawnCombatComponentFromActor(AActor* InActor)
{
	check(InActor != nullptr);

	if (IPawnCombatInterface* PawnCombatInterface = Cast<IPawnCombatInterface>(InActor))
	{
		return PawnCombatInterface->GetPawnCombatComponent();
	}

	return nullptr;
}

UPawnCombatComponent* UAvalonFunctionLibrary::BP_GetPawnCombatComponentFromActor(AActor* InActor,
	EAvalonValidType& OutValidType)
{
	UPawnCombatComponent* CombatComponent = NativeGetPawnCombatComponentFromActor(InActor);

	OutValidType = CombatComponent ? EAvalonValidType::Valid : EAvalonValidType::Invalid;
	
	return CombatComponent;
}
