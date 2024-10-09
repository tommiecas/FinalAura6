// Copyright Gravity Well Games


#include "AbilitySystem/Abilities/AuraArcaneShards.h"

FString UAuraArcaneShards::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	if (Level == 1)
	{
		return FString::Printf(TEXT(
			// Title
			"<Title>ARCANE SHARDS</>\n\n"

			// Level
			"<Small>Level: </><Level>%d</>\n"

			// ManaCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"

			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

			// Description
			"Summons a Shard of Damnation, \n"
			"to strike down your Enemies "
			"with radial Arcane Energy, "
			"conjured from the depths of Hell. \n\n"

			// Damage
			"Deals <Damage>%d</> Arcane Damage per shard, "
			"with a chance to condemn the souls struck "
			"to eternal <Debuff>Damnation</>. "),

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
		"<Title>ARCANE SHARDS</>\n\n"

		// Level
		"<Small>Level: </><Level>%d</>\n"

		// ManaCost
		"<Small>Cost (in Mana): </><ManaCost>%.1f</>\n"

		//Cooldown
		"<Small>Cooldown: </><Cooldown> %.1f</>\n\n"

		// Number of ShockTargets
		"Summons <NumProjectiles>%d</> Shards of Damnation, \n"
		"to strike down your Enemies "
		"with radial Arcane Energy, "
		"conjured from the depths of Hell. \n\n"
			
		// Damage
		"Deals <Damage>%d</> Arcane Damage per shard, "
		"with a chance to condemn the souls struck "
		"to eternal <Debuff>Damnation</>. "),

		// Values
		Level,
		ManaCost,
		Cooldown,
		FMath::Min(Level, MaxNumShards),
		ScaledDamage);
	}
}

FString UAuraArcaneShards::GetNextLevelDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	float Cooldown = GetCooldown(Level);
	return FString::Printf(TEXT(
		// Title
		"<Title>NEXT LEVEL:</>\n\n"

		// Level
		"<Small>Level: </><Level>%d</>\n"

		// ManaCost
		"<Small>Cost (in Mana): </><ManaCost>%.1f</>\n"

		//Cooldown
		"<Small>Cooldown: </><Cooldown> %.1f</>\n\n"

		// Number of ShockTargets
		"Summons <NumProjectiles>%d</> Shards of Damnation, \n"
		"to strike down your Enemies "
		"with radial Arcane Energy, "
		"conjured from the depths of Hell. \n\n"
			
		// Damage
		"Deals <Damage>%d</> Arcane Damage per shard, "
		"with a chance to condemn the souls struck "
		"to eternal <Debuff>Damnation</>. "),

		// Values
		Level,
		ManaCost,
		Cooldown,
		FMath::Min(Level, MaxNumShards),
		ScaledDamage);
}