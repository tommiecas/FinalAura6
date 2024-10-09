// Copyright Gravity Well Games


#include "AbilitySystem/Abilities/AuraFireBlast.h"

FString UAuraFireBlast::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	return FString::Printf(TEXT(
	// Title
	"<Title>FIREBLAST</>\n\n"

	// Level
	"<Small>Level: </><Level>%d</>\n"

	// ManaCost
	"<Small>ManaCost: </><ManaCost>%.1f</>\n"

	//Cooldown
	"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

	// Description
	"Launches <NumProjectiles>%d</> Fireballs \n"
	"outward in all directions, \n"
	"then double back, and explode upon their return. \n\n"

	// Damage
	"Deals <Damage>%d</> Radial Fire Damage with "
	"a chance to <Debuff>Burn</>"),

	//Values
	Level,
	ManaCost,
	Cooldown,
	NumFireBalls,
	ScaledDamage);
}


FString UAuraFireBlast::GetNextLevelDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	return FString::Printf(TEXT(
	// Title
	"<Title>NEXT LEVEL:</>\n\n"

	// Level
	"<Small>Level: </><Level>%d</>\n"

	// ManaCost
	"<Small>ManaCost: </><ManaCost>%.1f</>\n"

	//Cooldown
	"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

	// Description
	"Launches <NumProjectiles>%d</> Fireballs \n"
	"outward in all directions, \n"
	"then double back, and explode upon their return. \n\n"

	// Damage
	"Deals <Damage>%d</> Radial Fire Damage with "
	"a chance to <Debuff>Burn</>"),

	//Values
	Level,
	ManaCost,
	Cooldown,
	NumFireBalls,
	ScaledDamage);
}
