#include "stdafx.h"

Level::Level(const MainCharacter& mainCharacter, const Companion& companion, std::vector<Foe*>& enemies
			, const std::string& tilesetPath, float tileSize, const int level[], size_t width, size_t height
			, bool isEndLevel, const Level& nextLevel)
	: m_MainCharacter	{ mainCharacter }
	, m_Companion		{ companion }
	, m_Enemies			{ enemies }
	, m_IsEndLevel		{ isEndLevel }
	, m_NextLevel		{ nextLevel }
{
	m_Map.load(tilesetPath, { tileSize, tileSize }, level, width, height);
}

Level::~Level()
{
}
