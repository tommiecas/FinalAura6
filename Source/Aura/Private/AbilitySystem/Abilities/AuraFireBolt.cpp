// Copyright Gravity Well Games


#include "AbilitySystem/Abilities/AuraFireBolt.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AuraGameplayTags.h"
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
				"Deals <Damage>%d</><Default> Fire Damage with "
				"a chance to Burn</>"),

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
			"Launches<NumProjectiles>%d </><Default>Bolts of Fire, "
			"exploding on impact. </>\n"
			
			// Damage
			"<Default>Deals</><Damage>%d</><Default> Fire Damage with"
			" a chance to Burn</>"),

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
	"<Default>Launches</> <NumProjectiles>%d </><Default>Bolts of Fire, "
	"exploding on impact. </>\n"
			
	// Damage
	"<Default> Deals </><Damage>%d</><Default> Fire Damage with "
	"a chance to Burn.</>"),

	//Values
	Level,
	ManaCost,
	Cooldown,
	FMath::Min(Level, NumProjectiles),
	ScaledDamage);
}

void UAuraFireBolt::SpawnProjectiles(const FVector& ProjectileTargetLocation, const FGameplayTag& SocketTag,
	bool bOverridePitch, float PitchOverride, AActor* HomingTarget)
{
	const FVector SocketLocation = ICombatInterface::Execute_GetCombatSocketLocation(GetAvatarActorFromActorInfo(), SocketTag);
	FRotator Rotation = (ProjectileTargetLocation - SocketLocation).Rotation();

	FTransform SpawnTransform;
	SpawnTransform.SetLocation(SocketLocation);
	SpawnTransform.SetRotation(Rotation.Quaternion());
	if (bOverridePitch) Rotation.Pitch = PitchOverride;

	const FVector Forward = Rotation.Vector();
	const FVector LeftOfSpread = Forward.RotateAngleAxis(-ProjectileSpread / 2.f, FVector::UpVector);
	const FVector RightOfSpread = Forward.RotateAngleAxis(ProjectileSpread / 2.f, FVector::UpVector);

	//NumProjectiles = FMath::Min(MaxNumProjectiles, GetAbilityLevel());
	
	if (NumProjectiles > 1)
	{
		const float DeltaSpread = ProjectileSpread / (NumProjectiles - 1);
		for (int32 i = 0; 1 < NumProjectiles; i++)
		{
			const FVector Direction = LeftOfSpread.RotateAngleAxis(DeltaSpread * i, FVector::UpVector);
			const FVector Start = SocketLocation + FVector(0,0,10);
			UKismetSystemLibrary::DrawDebugArrow(GetAvatarActorFromActorInfo(),
				Start,
				Start + Direction * 75.f,
				1,
				FLinearColor::Red,
				120,
				1);
	
		}
	}
	else
	{
		const FVector Start = SocketLocation + FVector(0,0,10);
		UKismetSystemLibrary::DrawDebugArrow(GetAvatarActorFromActorInfo(),
				Start,
				Start + Forward * 75.f,
				1,
				FLinearColor::Red,
				120,
				1);
	}
	UKismetSystemLibrary::DrawDebugArrow(GetAvatarActorFromActorInfo(), SocketLocation, SocketLocation + LeftOfSpread * 100.f, 1, FLinearColor::Blue, 120, 1);
	UKismetSystemLibrary::DrawDebugArrow(GetAvatarActorFromActorInfo(), SocketLocation, SocketLocation + RightOfSpread * 100.f, 1, FLinearColor::Yellow, 120, 1);


}
