// Sam Hill All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartupData/DataAsset_StartupDataBase.h"
#include "DataAsset_HeroStartupData.generated.h"

struct FAvalonHeroAbilitySet;
/**
 * 
 */
UCLASS()
class AVALON_API UDataAsset_HeroStartupData : public UDataAsset_StartupDataBase
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UAvalonAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "StartupData", meta =(TitleProperty = "InputTag"))
	TArray<FAvalonHeroAbilitySet> HeroStartupAbilitySets;
	
	
};
