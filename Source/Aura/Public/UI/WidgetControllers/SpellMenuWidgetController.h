// Copyright Gravity Well Games

#pragma once

#include "CoreMinimal.h"
#include "AuraGameplayTags.h"
#include "UI/WidgetControllers/AuraWidgetController.h"
#include "GameplayTagContainer.h"
#include "SpellMenuWidgetController.generated.h"

struct FAuraGameplayTags;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FSpellGlobeSelectedSignature, bool, bSpendPointsButtonEnabled, bool,
                                             bEquipButtonEnabled, FString, DescriptionString, FString, NextLevelDescriptionString);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWaitFOrEquipSelectionSignature, const FGameplayTag&, AbilityType);

struct FSelectedAbility
{
	FGameplayTag Ability = FGameplayTag();
	FGameplayTag Status = FGameplayTag();
};
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class AURA_API USpellMenuWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

public:
    virtual void BroadcastInitialValues() override;
    virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerStatChangedSignature SpellPointsChanged;

	UPROPERTY(BlueprintAssignable)
	FSpellGlobeSelectedSignature SpellGlobeSelectedDelegate;

	UPROPERTY(BlueprintAssignable)
	FWaitFOrEquipSelectionSignature WaitForEquipDelegate;

	UPROPERTY(BlueprintAssignable)
	FWaitFOrEquipSelectionSignature StopWaitingForEquipDelegate;

	UFUNCTION(BlueprintCallable)
	void SpellGlobeSelected(const FGameplayTag& AbilityTag);

	UFUNCTION(BlueprintCallable)
	void SpellPointButtonPressed();

	UFUNCTION(BlueprintCallable)
	void GlobeDeselect();

	UFUNCTION(BlueprintCallable)
	void EquipButtonPressed();

private:
	void ShouldEnableButtons(const FGameplayTag& AbilityStatus, int32 SpellPoints, bool& ShouldEnableSpellPointsButton, bool& bShouldEnableEquipButton);
	FSelectedAbility SelectedAbility = { FAuraGameplayTags::Get().Abilities_None, FAuraGameplayTags::Get().Abilities_Status_Locked };
	int32 CurrentSpellPoints = 0;
	bool bWaitingForEquipSelection = false;
	
};
