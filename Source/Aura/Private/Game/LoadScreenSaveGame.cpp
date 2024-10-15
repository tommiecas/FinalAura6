// Copyright Gravity Well Games


#include "Game/LoadScreenSaveGame.h"

FSavedMap ULoadScreenSaveGame::GetSavedMapWithMapName(const FString& LevelName)
{
	for (const FSavedMap Map : SavedMaps)
	{
		if (Map.MapAssetName == LevelName)
		{
			return Map;
		}
	}
	return FSavedMap();
}

bool ULoadScreenSaveGame::HasMap(const FString& LevelName)
{
	for (const FSavedMap Map : SavedMaps)
	{
		if (Map.MapAssetName == LevelName)
		{
			return true;
		}
	}
	return false;
}
