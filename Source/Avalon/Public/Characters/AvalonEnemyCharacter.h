// Sam Hill All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Characters/AvalonBaseCharacter.h"
#include "AvalonEnemyCharacter.generated.h"

class UEnemyCombatComponent;
/**
 * 
 */
UCLASS()
class AVALON_API AAvalonEnemyCharacter : public AAvalonBaseCharacter
{
	GENERATED_BODY()

public:
	AAvalonEnemyCharacter();

	//~ Begin IPawnCombatInterface Interface.
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ End IPawnCombatInterface Interface.
	
protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface.
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	TObjectPtr<UEnemyCombatComponent> EnemyCombatComponent;

public:
	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent; }


private:
	void InitEnemyStartupData();
};
