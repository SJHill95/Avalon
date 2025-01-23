// Sam Hill All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/AvalonCharacterAnimInstance.h"
#include "AvalonHeroAnimInstance.generated.h"

class AAvalonHeroCharacter;
/**
 * 
 */
UCLASS()
class AVALON_API UAvalonHeroAnimInstance : public UAvalonCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|References")
	TObjectPtr<AAvalonHeroCharacter> OwnerHeroCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
	bool bShouldEnterRelaxState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
	float EnterRelaxStateThreshold = 5.f;
	
	float IdleElapsedTime;
};
