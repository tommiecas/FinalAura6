// Copyright Gravity Well Games


#include "AbilitySystem/Abilities/AuraFireBolt.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Actors/AuraProjectile.h"
#include "AbilitySystem/AuraAbilitySystemLibrary.h"
#include "Actors/AuraProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "AuraGameplayTags.h"
#include "AbilitySystem/AuraAbilitySystemLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

FString UAuraFireBolt::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	if (Level == 1)
		{
			return FString::Printf(TEXT(
				// Title
				"<Title>FIREBOLT</>\n\n"

				// Level
				"<Small>Level: </><Level>%d</>\n"

				// ManaCost
				"<Small>ManaCost: </><ManaCost>%.1f</>\n"

				//Cooldown
				"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

				// Description
				"Launches a Bolt of Fire, "
				"exploding on impact. \n"

				// Damage
				"Deals <Damage>%d</> Fire Damage with "
				"a chance to <Debuff>Burn</>"),

				//Values
				Level,
				ManaCost,
				Cooldown,
				ScaledDamage);
		}
		else
		{
			return FString::Printf(TEXT(
			// Title
			"<Title>FIREBOLT</>\n\n"

			// Level
			"<Small>Level: </><Level>%d</>\n"

			// ManaCost
			"<Small>Cost (in Mana): </><ManaCost>%.1f</>\n"

			//Cooldown
			"<Small>Cooldown: </><Cooldown> %.1f</>\n\n"

			// Number of FireBolts
			"Launches <NumProjectiles>%d</> Bolts of Fire, "
			"exploding on impact. \n\n"
			
			// Damage
			"Deals <Damage>%d</> Fire Damage with"
			" a chance to <Debuff>Burn</>."),

			// Values
			Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level, NumProjectiles),
			ScaledDamage);
		}
}

FString UAuraFireBolt::GetNextLevelDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	float Cooldown = GetCooldown(Level);
	return FString::Printf(TEXT(
	// Title
	"<Title>NEXT LEVEL: </>\n\n"

	// Level
	"<Small>Level: </><Level>%d</>\n"

	// ManaCost
	"<Small>ManaCost: </><ManaCost>%.1f</>\n"

	//Cooldown
	"<Small>Cooldown: </><Cooldown> %.1f</>\n\n"

	// Number of FireBolts
	"Launches <NumProjectiles>%d</> Bolts of Fire, "
	"exploding on impact. \n\n"
			
	// Damage
	"Deals <Damage>%d</> Fire Damage with "
	"a chance to <Debuff>Burn</>."),

	//Values
	Level,
	ManaCost,
	Cooldown,
	FMath::Min(Level, NumProjectiles),
	ScaledDamage);
}

void UAuraFireBolt::SpawnProjectiles(const FVector& ProjectileTargetLocation, const FGameplayTag& SocketTag, bool bOverridePitch, float PitchOverride, AActor* HomingTarget)
{
	const bool bIsServer = GetAvatarActorFromActorInfo()->HasAuthority();
	if (!bIsServer) return;

	const FVector SocketLocation = ICombatInterface::Execute_GetCombatSocketLocation(
		GetAvatarActorFromActorInfo(),
		SocketTag);
	FRotator Rotation = (ProjectileTargetLocation - SocketLocation).Rotation();
	if (bOverridePitch) Rotation.Pitch = PitchOverride;
	
	const FVector Forward = Rotation.Vector();
	const int32 EffectiveNumProjectiles = FMath::Min(NumProjectiles, GetAbilityLevel());
	TArray<FRotator> Rotations = UAuraAbilitySystemLibrary::EvenlySpacedRotators(Forward, FVector::UpVector, ProjectileSpread, EffectiveNumProjectiles);

	for (const FRotator& Rot : Rotations)
	{
		FTransform SpawnTransform;
		SpawnTransform.SetLocation(SocketLocation);
		SpawnTransform.SetRotation(Rot.Quaternion());

		AAuraProjectile* Projectile = GetWorld()->SpawnActorDeferred<AAuraProjectile>(
		ProjectileClass,
		SpawnTransform,
		GetOwningActorFromActorInfo(),
		Cast<APawn>(GetOwningActorFromActorInfo()),
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	
		Projectile->DamageEffectParams = MakeDamageEffectParamsFromClassDefaults();

		if (HomingTarget && HomingTarget->Implements<UCombatInterface>())
		{
			Projectile->ProjectileMovement->HomingTargetComponent = HomingTarget->GetRootComponent();
		}
		else
		{
			Projectile->HomingTargetSceneComponent = NewObject<USceneComponent>(USceneComponent::StaticClass());
			Projectile->HomingTargetSceneComponent->SetWorldLocation(ProjectileTargetLocation);
			Projectile->ProjectileMovement->HomingTargetComponent = Projectile->HomingTargetSceneComponent;
		}
		Projectile->ProjectileMovement->HomingAccelerationMagnitude = FMath::FRandRange(HomingAccelerationMin, HomingAccelerationMax);
		Projectile->ProjectileMovement->bIsHomingProjectile = bLaunchHomingProjectiles;
		
		Projectile->FinishSpawning(SpawnTransform);
	}
}