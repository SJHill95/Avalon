// Sam Hill All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AvalonWeaponBase.generated.h"

class UBoxComponent;

DECLARE_DELEGATE_OneParam(FOnTargetInteractedDelegate, AActor*)

UCLASS()
class AVALON_API AAvalonWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AAvalonWeaponBase();

	FOnTargetInteractedDelegate OnWeaponHitTarget;

	FOnTargetInteractedDelegate OnWeaponPulledFromTarget;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapons")
	TObjectPtr<UStaticMeshComponent> WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapons")
	TObjectPtr<UBoxComponent> WeaponCollisionBox;

	UFUNCTION()
	virtual void OnCollisionBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
		);

	UFUNCTION()
	virtual void OnCollisionEndOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex
		);

public:
	FORCEINLINE UBoxComponent* GetWeaponCollisionBox() const { return WeaponCollisionBox; }
};
