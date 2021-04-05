#include "stdafx.h"

Level::Level(MainCharacter& player, Companion& companion, std::vector<Foe*>& enemies, std::vector<Checkpoint*>& checkpoints
			, const std::string& tilesetPath, float tileSize, const std::vector<std::string>& level, size_t width, size_t height
			, bool startLevel, bool endLevel)
	: m_StartLevel		{ startLevel }
	, m_EndLevel		{ endLevel }
{
	m_Map.load(tilesetPath, { tileSize, tileSize }, level, width, height, player, companion, enemies, checkpoints);
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
