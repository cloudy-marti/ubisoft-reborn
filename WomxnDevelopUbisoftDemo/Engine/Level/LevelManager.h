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

	TileMap LoadFirstLevel(MainCharacter&, Companion&, std::vector<Foe*>&);
	TileMap LoadSecondLevel(MainCharacter&, Companion&, std::vector<Foe*>&);
	TileMap LoadThirdLevel(MainCharacter&, Companion&, std::vector<Foe*>&);
	
	void Update() override;

private:
	LevelManager();
	static LevelManager* _Instance;

	TileMap LoadLevel(MainCharacter&, Companion&, std::vector<Foe*>&, const std::string&, const std::vector<std::string>&, const std::string&);
	std::vector<Level*> m_Level_1;

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

