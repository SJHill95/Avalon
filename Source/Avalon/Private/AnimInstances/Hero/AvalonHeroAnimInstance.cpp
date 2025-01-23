// Sam Hill All Rights Reserved


#include "AnimInstances/Hero/AvalonHeroAnimInstance.h"

#include "Characters/AvalonHeroCharacter.h"

void UAvalonHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwnerCharacter)
	{
		OwnerHeroCharacter = Cast<AAvalonHeroCharacter>(OwnerCharacter);
	}
	
}

void UAvalonHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (bHasAcceleration)
	{
		IdleElapsedTime = 0.f;
		bShouldEnterRelaxState = false;
	}
	else
	{
		IdleElapsedTime += DeltaSeconds;
		bShouldEnterRelaxState = (IdleElapsedTime > EnterRelaxStateThreshold);
	}
	
}
