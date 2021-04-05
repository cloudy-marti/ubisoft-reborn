#include "stdafx.h"

LevelManager* LevelManager::_Instance = nullptr;

LevelManager::LevelManager()
{}

LevelManager* LevelManager::GetInstance()
{
    if (_Instance == nullptr)
    {
        _Instance = new LevelManager();
    }
    return _Instance;
}

[[nodiscard]] TileMap LevelManager::LoadLevel(MainCharacter& player, Companion& companion, std::vector<Foe*>& enemies,
    const std::string& tileset, const std::vector<std::string>& tilemap, const std::string& texturePath)
{
    Level* map_1 = new Level { player, companion, enemies, tileset, 32.f, tilemap, 36, 36, true, false};
    map_1->SetEnemiesTexture(texturePath);
    m_Level_1.emplace_back(map_1);
    return map_1->GetMap();
}

TileMap LevelManager::LoadFirstLevel(MainCharacter& player, Companion& companion, std::vector<Foe*>& enemies)
{
    return LoadLevel(player, companion, enemies, Level_1::Level_1_Tileset, Level_1::Level_1_Map_1, Level_1::Level_1_Foe_Texture);
}

TileMap LevelManager::LoadSecondLevel(MainCharacter& player, Companion& companion, std::vector<Foe*>& enemies)
{
    return LoadLevel(player, companion, enemies, Level_1::Level_1_Tileset, Level_1::Level_1_Map_2, Level_1::Level_1_Foe_Texture);
}

TileMap LevelManager::LoadThirdLevel(MainCharacter& player, Companion& companion, std::vector<Foe*>& enemies)
{
    return LoadLevel(player, companion, enemies, Level_1::Level_1_Tileset, Level_1::Level_1_Map_3, Level_1::Level_1_Foe_Texture);
}

void LevelManager::Update()
{
}
