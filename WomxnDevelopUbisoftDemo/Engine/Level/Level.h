#pragma once

#include <vector>

#include <Game/Character/MainCharacter.h>
#include <Game/Character/Companion.h>
#include <Game/Character/Foe.h>

#include <Engine/Level/TileMap.h>

class Level
{
public:
	Level(MainCharacter&, Companion&, std::vector<Foe*>&, const std::string& , float, const std::vector<std::string>&, size_t, size_t, bool, bool);
	~Level();

	//void LoadLevel(const std::string& filepath, const std::string& map);

	inline bool IsStartLevel() const { return m_StartLevel; }
	inline bool IsEndLevel() const { return m_EndLevel; }

	inline TileMap GetMap() const { return m_Map; }

	inline void SetPreviousLevel(const Level& previous) { m_previousLevel = &previous; }
	inline void SetNextLevel(const Level& next) { m_nextLevel = &next; }

	inline void SetPosition(Character& character, sf::Vector2f position) { character.setPosition(position); }

	void SetEnemiesTexture(const std::string&, std::vector<Foe*>& enemies);

private:
	TileMap m_Map;

	bool m_StartLevel;
	bool m_EndLevel;

	const Level* m_previousLevel = nullptr;
	const Level* m_nextLevel = nullptr;
};

