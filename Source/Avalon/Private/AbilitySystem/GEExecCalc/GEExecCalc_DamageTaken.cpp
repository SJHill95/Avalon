// Sam Hill All Rights Reserved


#include "AbilitySystem/GEExecCalc/GEExecCalc_DamageTaken.h"
#include "AbilitySystem/AvalonAttributeSet.h"

struct FAvalonDamageCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefencePower)

	FAvalonDamageCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAvalonAttributeSet, AttackPower, Source, false)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAvalonAttributeSet, DefencePower,Target,false)
	}
};

static const FAvalonDamageCapture& GetAvalonDamageCapture()
{
	static FAvalonDamageCapture AvalonDamageCapture;
	return AvalonDamageCapture;
}

UGEExecCalc_DamageTaken::UGEExecCalc_DamageTaken()
{
	/* Slow way of doing capure */
	/*FProperty* AttackPowerProperty = FindFieldChecked<FProperty>(UAvalonAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UAvalonAttributeSet, AttackPower));
	FGameplayEffectAttributeCaptureDefinition AtackPowerCaptureDefinition(AttackPowerProperty, EGameplayEffectAttributeCaptureSource::Source, false);
	RelevantAttributesToCapture.Add(AtackPowerCaptureDefinition);*/

	RelevantAttributesToCapture.Add(GetAvalonDamageCapture().AttackPowerDef);
	RelevantAttributesToCapture.Add(GetAvalonDamageCapture().DefencePowerDef);
}

