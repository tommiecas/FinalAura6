// Copyright Gravity Well Games

#include "Actors/AuraEnemySpawnPoint.h"

#include "Characters/AuraEnemy.h"

void AAuraEnemySpawnPoint::SpawnEnemy() const
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	AAuraEnemy* Enemy = GetWorld()->SpawnActorDeferred<AAuraEnemy>(EnemyClass, GetActorTransform());
	Enemy->SetLevel(EnemyLevel);
	Enemy->SetCharacterClass(CharacterClass);
	Enemy->FinishSpawning(GetActorTransform());
	Enemy->SpawnDefaultController();
}