// Sam Hill All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/AvalonBaseAnimInstance.h"
#include "AvalonHeroLinkedAnimLayer.generated.h"

class UAvalonHeroAnimInstance;
/**
 * 
 */
UCLASS()
class AVALON_API UAvalonHeroLinkedAnimLayer : public UAvalonBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	UAvalonHeroAnimInstance* GetHeroAnimInstance() const;
};
