// Copyright Gravity Well Games


#include "AbilitySystem/Abilities/AuraFireBolt.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AuraGameplayTags.h"

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
