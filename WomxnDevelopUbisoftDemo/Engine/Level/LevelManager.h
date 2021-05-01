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

	//TileMap LoadLevel_4(MainCharacter&, Companion&, std::vector<Foe*>&, std::vector<Checkpoint*>&);
	
	void Start(MainCharacter&, Companion&, std::vector<Foe*>&, std::vector<Checkpoint*>, TileMap&);
	void LoadFirstLevel(MainCharacter&, Companion&, std::vector<Foe*>&, std::vector<Checkpoint*>, TileMap&);

	// TODO this is not the right way
	bool m_ReadyForSecondMap = false;
	bool m_ReadyForThirdMap = false;
	bool m_EndGame = false;
	int m_Level = 0;
private:
	class Level_1
	{
	private:
		static const std::string Level_1_Foe_Texture;

		static const std::string Level_1_Tileset;
		static const std::vector<std::string> Level_1_Map_1;
		static const std::vector<std::string> Level_1_Map_2;
		static const std::vector<std::string> Level_1_Map_3;

		int m_Event = 0;
		bool m_EndOfLevel = false;

	public:
		TileMap LoadLevel_1(MainCharacter&, Companion&, std::vector<Foe*>&, std::vector<Checkpoint*>&);
		TileMap LoadLevel_2(MainCharacter&, Companion&, std::vector<Foe*>&, std::vector<Checkpoint*>&);
		TileMap LoadLevel_3(MainCharacter&, Companion&, std::vector<Foe*>&, std::vector<Checkpoint*>&);
		
		inline int GetStep() const { return m_Event; };

		void FinishLevel() { m_EndOfLevel = true; }
		bool IsFinished() const { return m_EndOfLevel; };
	};

	LevelManager();
	static LevelManager* _Instance;

	void Update() override {}
	
	[[nodiscard]] TileMap LoadLevel(MainCharacter&, Companion&, std::vector<Foe*>&, std::vector<Checkpoint*>&, const std::string&, const std::vector<std::string>&, const std::string&, bool, bool);
	
	Level_1 m_Level_1;
};

