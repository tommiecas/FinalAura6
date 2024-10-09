// Copyright Gravity Well Games


#include "AbilitySystem/Abilities/AuraElectrocute.h"

FString UAuraElectrocute::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	if (Level == 1)
	{
		return FString::Printf(TEXT(
			// Title
			"<Title>ELECTROCUTE</>\n\n"

			// Level
			"<Small>Level: </><Level>%d</>\n"

			// ManaCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"

			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

			// Description
			"Emits a beam of lightning, "
			"electrocuting the Target. \n\n"
			

			// Damage
			"Deals <Damage>%d</> Lightning Damage per second with "
			"a chance to <Debuff>Stun</>."),

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
		"<Title>ELECTROCUTE</>\n\n"

		// Level
		"<Small>Level: </><Level>%d</>\n"

		// ManaCost
		"<Small>Cost (in Mana): </><ManaCost>%.1f</>\n"

		//Cooldown
		"<Small>Cooldown: </><Cooldown> %.1f</>\n\n"

		// Number of ShockTargets
		"Emits a beam of Lightning, "
		"electrocuting the Target, "
		"and propagating to <NumProjectiles>%d</> additional targets nearby. \n\n"
			
		// Damage
		"<Default>Deals </><Damage> %d</> Lightning Damage per second with"
		" a chance to <Debuff>Stun</>."),

		// Values
		Level,
		ManaCost,
		Cooldown,
		FMath::Min(Level, MaxNumShockTargets - 1),
		ScaledDamage);
	}
}

FString UAuraElectrocute::GetNextLevelDescription(int32 Level)
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
			"<Small>Cost (in Mana): </><ManaCost>%.1f</>\n"

			//Cooldown
			"<Small>Cooldown: </><Cooldown> %.1f</>\n\n"

			// Number of ShockTargets
			"Emits a beam of Lightning, "
			"electrocuting the Target, "
			"and propagating to <NumProjectiles>%d</> additional target(s) nearby. \n\n"
			
			// Damage
			"<Default>Deals </><Damage> %d</> Lightning Damage per second with"
			" a chance to <Debuff>Stun</>."),

			// Values
			Level == 1.f ? Level : Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level - 1, MaxNumShockTargets - 1),
			ScaledDamage);
}

	
