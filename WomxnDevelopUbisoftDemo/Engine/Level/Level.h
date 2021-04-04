#pragma once

#include <vector>

#include <Game/Character/MainCharacter.h>
#include <Game/Character/Companion.h>
#include <Game/Character/Foe.h>

#include <Engine/Level/TileMap.h>

class Level
{
public:
	Level(const MainCharacter&, const Companion&, std::vector<Foe*>&, const std::string& , float, const std::vector<std::string>&, size_t, size_t, bool, const Level&);
	~Level();

private:
	TileMap m_Map;

	const MainCharacter& m_MainCharacter;
	const Companion& m_Companion;
	std::vector<Foe*> m_Enemies;

	bool m_IsEndLevel;
	const Level& m_NextLevel;
};

