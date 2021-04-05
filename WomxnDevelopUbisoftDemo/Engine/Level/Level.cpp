#include "stdafx.h"

Level::Level(MainCharacter& mainCharacter, Companion& companion, std::vector<Foe*>& enemies
			, const std::string& tilesetPath, float tileSize, const std::vector<std::string>& level, size_t width, size_t height
			, bool startLevel, bool endLevel)
	//: m_Map				{ map }
	: m_MainCharacter	{ mainCharacter }
	, m_Companion		{ companion }
	, m_Enemies			{ enemies }
	, m_StartLevel		{ startLevel }
	, m_EndLevel		{ endLevel }
{
	m_Map.load(tilesetPath, { tileSize, tileSize }, level, width, height, m_MainCharacter, m_Companion, m_Enemies);
}

Level::~Level()
{
}

void Level::SetEnemiesTexture(const std::string& texturePath, std::vector<Foe*>& enemies)
{
	for (Foe* enemy : enemies)
	{
		enemy->SetTexture(texturePath);
	}
}
