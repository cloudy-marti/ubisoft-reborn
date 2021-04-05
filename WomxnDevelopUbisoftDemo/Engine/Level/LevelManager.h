#pragma once
#include <Engine/Manager.h>
#include <Engine/Level/Level.h>

class MainCharacter;
class Companion;
class Foe;

class LevelManager : public Manager
{
public:
	static LevelManager* GetInstance();

	TileMap LoadLevel_1(MainCharacter&, Companion&, std::vector<Foe*>&, std::vector<Checkpoint*>&);
	TileMap LoadLevel_2(MainCharacter&, Companion&, std::vector<Foe*>&, std::vector<Checkpoint*>&);
	TileMap LoadLevel_3(MainCharacter&, Companion&, std::vector<Foe*>&, std::vector<Checkpoint*>&);
	//TileMap LoadLevel_4(MainCharacter&, Companion&, std::vector<Foe*>&, std::vector<Checkpoint*>&);
	
	void Update() override;

	// TODO this is not the right way
	bool m_ReadyForSecondMap = false;
	bool m_ReadyForThirdMap = false;
	int m_Level = 0;
private:
	LevelManager();
	static LevelManager* _Instance;

	[[nodiscard]] TileMap LoadLevel(MainCharacter&, Companion&, std::vector<Foe*>&, std::vector<Checkpoint*>&, const std::string&, const std::vector<std::string>&, const std::string&, bool, bool);
	
	class Level_1
	{
	public:
		static const std::string Level_1_Foe_Texture;

		static const std::string Level_1_Tileset;
		static const std::vector<std::string> Level_1_Map_1;
		static const std::vector<std::string> Level_1_Map_2;
		static const std::vector<std::string> Level_1_Map_3;
	};
};

