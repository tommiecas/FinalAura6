// Copyright Gravity Well Games

#pragma once

#include "CoreMinimal.h"
#include "AuraCheckpoint.h"
#include "MapEntrance.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AMapEntrance : public AAuraCheckpoint
{
	GENERATED_BODY()

public:
	AMapEntrance(const FObjectInitializer& ObjectInitializer);
	
	/* Highlight Interface */
	virtual void HighlightActor_Implementation() override;
	/* End Highlight Interface */

	/* Save Interface */
	virtual void LoadActor_Implementation() override;
	/* End Save Interface */

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UWorld> DestinationMap;

	UPROPERTY(EditAnywhere)
	FName DestinationPlayerStartTag;

public:
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
};