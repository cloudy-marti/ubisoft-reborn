#include "stdafx.h"
#include "LevelManager.h"

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
