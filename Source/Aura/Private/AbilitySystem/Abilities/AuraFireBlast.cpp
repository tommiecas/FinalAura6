// Copyright Gravity Well Games


#include "AbilitySystem/Abilities/AuraFireBlast.h"
#include "Actors/AuraFireBall.h"
#include "AbilitySystem/AuraAbilitySystemLibrary.h"

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
	"which then double back, \n"
	"and explode upon their return. \n\n"

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
	"which then double back, \n"
	"and explode upon their return. \n\n"

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

TArray<AAuraFireBall*> UAuraFireBlast::SpawnFireBalls()
{
	TArray<AAuraFireBall*> FireBalls;
	const FVector Forward = GetAvatarActorFromActorInfo()->GetActorForwardVector();
	const FVector Location = GetAvatarActorFromActorInfo()->GetActorLocation();
	TArray<FRotator> Rotators = UAuraAbilitySystemLibrary::EvenlySpacedRotators(Forward, FVector::UpVector, 360.f, NumFireBalls);

	for (const FRotator& Rotator : Rotators)
	{
		FTransform SpawnTransform;
		SpawnTransform.SetLocation(Location);
		SpawnTransform.SetRotation(Rotator.Quaternion());
		AAuraFireBall* FireBall = GetWorld()->SpawnActorDeferred<AAuraFireBall>(
			FireBallClass,
			SpawnTransform,
			GetOwningActorFromActorInfo(),
			CurrentActorInfo->PlayerController->GetPawn(),
			ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
		
		FireBall->DamageEffectParams = MakeDamageEffectParamsFromClassDefaults();
		FireBall->ReturnToActor = GetAvatarActorFromActorInfo();

		FireBalls.Add(FireBall);

		FireBall->FinishSpawning(SpawnTransform);

	}
	return FireBalls;

}
