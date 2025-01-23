// Sam Hill All Rights Reserved

#include "AnimInstances/AvalonCharacterAnimInstance.h"

#include "Characters/AvalonBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UAvalonCharacterAnimInstance::NativeInitializeAnimation()
{
	OwnerCharacter = Cast<AAvalonBaseCharacter>(TryGetPawnOwner());

	if (OwnerCharacter)
	{
		OwnerMovementComponent = OwnerCharacter->GetCharacterMovement();
	}
}

void UAvalonCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwnerCharacter || !OwnerMovementComponent)
	{
		return;
	}

	GroundSpeed = OwnerCharacter->GetVelocity().Size2D();

	bHasAcceleration = OwnerMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;

	Velocity = OwnerMovementComponent->Velocity;

	bIsFalling = OwnerMovementComponent->IsFalling();
	
}
