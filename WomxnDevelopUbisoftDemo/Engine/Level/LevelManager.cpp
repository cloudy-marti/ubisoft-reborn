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

[[nodiscard]] TileMap LevelManager::LoadLevel(MainCharacter& player, Companion& companion, std::vector<Foe*>& enemies, std::vector<Checkpoint*>& checkpoints,
    const std::string& tileset, const std::vector<std::string>& tilemap, const std::string& texturePath, bool start, bool end)
{
    std::vector<BoxCollideable*>& colliders = PhysicsEngine::GetInstance()->m_Colliders;
    colliders.erase(std::remove_if(colliders.begin(), colliders.end(), [](BoxCollideable* bbox) { return bbox->getTag() == BoxCollideable::Tag::WALL || bbox->getTag() == BoxCollideable::Tag::CHECKPOINT; }), colliders.end());

    Level* map_1 = new Level { player, companion, enemies, checkpoints, tileset, 32.f, tilemap, 36, 36, start, end};
    map_1->SetEnemiesTexture(texturePath, enemies);
    return map_1->GetMap();
}

TileMap LevelManager::LoadLevel_1(MainCharacter& player, Companion& companion, std::vector<Foe*>& enemies, std::vector<Checkpoint*>& checkpoints)
{
    m_Level = 1;
    return LoadLevel(player, companion, enemies, checkpoints, Level_1::Level_1_Tileset, Level_1::Level_1_Map_1, Level_1::Level_1_Foe_Texture, true, false);
}

TileMap LevelManager::LoadLevel_2(MainCharacter& player, Companion& companion, std::vector<Foe*>& enemies, std::vector<Checkpoint*>& checkpoints)
{
    m_Level = 2;
    return LoadLevel(player, companion, enemies, checkpoints, Level_1::Level_1_Tileset, Level_1::Level_1_Map_2, Level_1::Level_1_Foe_Texture, false, false);
}

TileMap LevelManager::LoadLevel_3(MainCharacter& player, Companion& companion, std::vector<Foe*>& enemies, std::vector<Checkpoint*>& checkpoints)
{
    m_Level = 3;
    return LoadLevel(player, companion, enemies, checkpoints, Level_1::Level_1_Tileset, Level_1::Level_1_Map_3, Level_1::Level_1_Foe_Texture, false, false);
}

void LevelManager::Update()
{
}
