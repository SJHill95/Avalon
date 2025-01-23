// Sam Hill All Rights Reserved


#include "AnimInstances/Hero/AvalonHeroLinkedAnimLayer.h"
#include "AnimInstances/Hero/AvalonHeroAnimInstance.h"

UAvalonHeroAnimInstance* UAvalonHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UAvalonHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
