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
    std::vector<std::unique_ptr<BoxCollideable>>& colliders = PhysicsEngine::GetInstance()->m_Colliders;
    colliders.erase(std::remove_if(colliders.begin(), colliders.end(),
        [](std::unique_ptr<BoxCollideable>& bbox) { return bbox->getTag() == BoxCollideable::Tag::WALL || bbox->getTag() == BoxCollideable::Tag::CHECKPOINT; }),
        colliders.end());

    Level* map_1 = new Level { player, companion, enemies, checkpoints, tileset, 32.f, tilemap, 36, 36, start, end};
    map_1->SetEnemiesTexture(texturePath, enemies);
    return map_1->GetMap();
}

void LevelManager::Start(MainCharacter& player, Companion& companion, std::vector<Foe*>& enemies, std::vector<Checkpoint*> checkpoints, TileMap& map)
{
    LoadFirstLevel(player, companion, enemies, checkpoints, map);
}

void LevelManager::LoadFirstLevel(MainCharacter& player, Companion& companion, std::vector<Foe*>& enemies, std::vector<Checkpoint*> checkpoints, TileMap& map)
{
    if (m_Level_1.GetStep() == 0)
    {
        map = m_Level_1.LoadLevel_1(player, companion, enemies, checkpoints);
    }
    if (m_Level_1.GetStep() == 1 && player.m_SteppedOnCheckPoint)
    {
        player.m_SteppedOnCheckPoint = false;
        map = m_Level_1.LoadLevel_2(player, companion, enemies, checkpoints);
    }
    else if (m_Level_1.GetStep() == 2 && player.m_HasDiedOnce)
    {
        map = m_Level_1.LoadLevel_3(player, companion, enemies, checkpoints);
    }
    else if (m_Level_1.GetStep() == 3 && player.m_SteppedOnCheckPoint && companion.IsAttached() /*&& m_Enemies.empty()*/)
    {
        player.m_SteppedOnCheckPoint = false;
        m_Level_1.FinishLevel();
    }

    if (m_Level_1.IsFinished())
    {
        m_EndGame = true;
    }
}
