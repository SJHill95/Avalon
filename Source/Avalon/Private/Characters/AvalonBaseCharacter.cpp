// Sam Hill All Rights Reserved


#include "Characters/AvalonBaseCharacter.h"

#include "AbilitySystem/AvalonAbilitySystemComponent.h"
#include "AbilitySystem/AvalonAttributeSet.h"

// Sets default values
AAvalonBaseCharacter::AAvalonBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	AvalonAbilitySystemComponent = CreateDefaultSubobject<UAvalonAbilitySystemComponent>(TEXT("AvalonAbilitySystemComponent"));
	
	AvalonAttributeSet = CreateDefaultSubobject<UAvalonAttributeSet>(TEXT("AvalonAttributeSet"));
}

UAbilitySystemComponent* AAvalonBaseCharacter::GetAbilitySystemComponent() const
{
	return GetAvalonAbilitySystemComponent();
}

UPawnCombatComponent* AAvalonBaseCharacter::GetPawnCombatComponent() const
{
	return nullptr;
}

void AAvalonBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (AvalonAbilitySystemComponent)
	{
		AvalonAbilitySystemComponent->InitAbilityActorInfo(this, this);

		ensureMsgf(!CharacterStartupData.IsNull(), TEXT("Forgot to assign start up data to %s"), *GetName());
	}
}


