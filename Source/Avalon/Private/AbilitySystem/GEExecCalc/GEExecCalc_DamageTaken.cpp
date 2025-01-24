// Sam Hill All Rights Reserved


#include "AbilitySystem/GEExecCalc/GEExecCalc_DamageTaken.h"
#include "AbilitySystem/AvalonAttributeSet.h"
#include "AvalonGameplayTags.h"

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

void UGEExecCalc_DamageTaken::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& EffectSpec = ExecutionParams.GetOwningSpec();

	/*EffectSpec.GetContext().GetSourceObject();
	EffectSpec.GetContext().GetAbility();
	EffectSpec.GetContext().GetInstigator();
	EffectSpec.GetContext().GetEffectCauser();*/
	
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = EffectSpec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = EffectSpec.CapturedTargetTags.GetAggregatedTags();

	float SourceAttackPower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetAvalonDamageCapture().AttackPowerDef, EvaluateParameters, SourceAttackPower);

	float BaseDamage = 0.f;
	int32 UsedLightAttackComboCount = 0;
	int32 UsedHeavyAttackComboCount = 0;
	
	for (const TPair<FGameplayTag, float>& TagMagnitude : EffectSpec.SetByCallerTagMagnitudes)
	{
		if (TagMagnitude.Key.MatchesTagExact(AvalonGameplayTags::Shared_SetByCaller_BaseDamage))
		{
			BaseDamage = TagMagnitude.Value;
		}
		
		if (TagMagnitude.Key.MatchesTagExact(AvalonGameplayTags::Player_SetByCaller_AttackType_Light))
		{
			UsedLightAttackComboCount = TagMagnitude.Value;
		}

		if (TagMagnitude.Key.MatchesTagExact(AvalonGameplayTags::Player_SetByCaller_AttackType_Heavy))
		{
			UsedHeavyAttackComboCount = TagMagnitude.Value;
		}
	}
	
	float TargetDefencePower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetAvalonDamageCapture().DefencePowerDef, EvaluateParameters, TargetDefencePower);
}

