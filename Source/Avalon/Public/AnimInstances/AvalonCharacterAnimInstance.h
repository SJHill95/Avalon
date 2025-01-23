// Sam Hill All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/AvalonBaseAnimInstance.h"
#include "AvalonCharacterAnimInstance.generated.h"

class AAvalonBaseCharacter;
class UCharacterMovementComponent;
/**
 * 
 */
UCLASS()
class AVALON_API UAvalonCharacterAnimInstance : public UAvalonBaseAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()
	TObjectPtr<AAvalonBaseCharacter> OwnerCharacter;

	UPROPERTY()
	TObjectPtr<UCharacterMovementComponent> OwnerMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
	bool bHasAcceleration;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
	FVector Velocity;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
	bool bIsFalling;
};
