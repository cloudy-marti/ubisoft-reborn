#include <stdafx.h>

const std::string LevelManager::Level_1::Level_1_Foe_Texture{ "Assets\\character\\skeleton.png" };

const std::string LevelManager::Level_1::Level_1_Tileset{ "Assets\\level\\dreamset.png" };
const std::vector<std::string> LevelManager::Level_1::Level_1_Map_1
{
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2",
    "2","2","2","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2","2","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","3:","3","3","3:","0","0","1","0","1","1","1","0","0","1","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","3:","3","3","3:","0","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0p","0","1","0","0","0","3:","3:","3:","3:","7x","7x","0","0","0","1","1","1","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","5:","6:","0","7","0x","1x","0","0","0","1","1","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","1","0","0","0","0","0","0","1","0","5:","5:","7","7","0","0x","0x","0","1","0","0","1","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","6:","5:","0","0","7","0x","0x","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","0","0","0","7","0","7","0x","0x","1","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","0","0","7","0","0","0","0x","0x","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","0","0","7","0","0","0","0x","0x","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","6:","5:","5:","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2","5","5","6","5","5","5","5","5","5","5","5","6","5","5","5","5","5","5:","0","0","1","0","0","1","0","0","2:","2","2","2","2","2",
    "2","2","2","2","5","5","5","5","5","5","6","5","6","5","5","5","5","6","5","5","5","5:","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2","6","5","5","5","5","5","5","5","5","5","5","5","5","5","5","5","5","5:","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","5:","5:","5:","5:","5:","6:","5:","5:","5:","5:","5:","6:","5:","5:","5:","5:","5:","5:","0","0","0","0","1","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","1","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","1","1","1","0","0","0","0","0","0","0","1","0","0","0","0","0","0","0","0","0","1","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","1c","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","1","0","0","0","0","0","0","3:","3","3","3","3","3","3","3","3","3","3","3","3","3","3","2","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","3:","3","3","3","3","3","3","3","3","3","3","3","3","3","3","2","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0x","0x","0x","0x","0x","0x","0","2:","2","2","2","2","2",
    "2","2","2","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","0x","0x","0x","0x","0x","0x","2:","2:","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2:","2:","2:","2:","2:","2:","2:","2:","2","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2"
};

const std::vector<std::string> LevelManager::Level_1::Level_1_Map_2
{
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2",
    "2","2","2","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2","2","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","3:","3","3","3:","0","0","1","0","1","1","1","0","0","1","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","3:","3","3","3:","0","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","1","0","0","0","3:","3:","3:","3:","7","7","0","0","0","1","1","1","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","6:","5:","0","7","0","1","0","0","0","1","1","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","1","0","0","0","0","0","0","1","0","5:","6:","7","7","0","0","0","0f","1","0","0","1","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","5:","5:","0","0","7","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","4:","4:","7","0","7","0","0","0","1","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","0","4:","4:","0","0","0p","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","4:","4:","4:","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2","5","5","5","5","5","5","6","5","5","5","5","5","5","6","5","5","5","5:","4:","0","4:","0","4:","1","0","0","2:","2","2","2","2","2",
    "2","2","2","2","5","6","5","5","5","5","5","5","5","6","5","6","5","5","6","5","5","6:","4:","4:","4:","4:","4:","4:","0","0","2:","2","2","2","2","2",
    "2","2","2","2","5","5","5","5","6","5","5","6","5","5","5","5","5","6","5","5","5","5:","0","0","0","4:","4:","4:","4:","4:","2:","2","2","2","2","2",
    "2","2","2","2:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","0","0","0","0","1","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","1","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","1","1","1","0","0","0","0","0","0","0","1","0","0","0","0","0","0","0","0","0","1","0","0f","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","1","0","0","0","0","0","0","3:","3","3","3","3","3","3","3","3","3","3","3","3","3","3","2","2","2","2","2","2",
    "2","2","2","2:","0","0","0c","0","0","0","0","0","0","0","0","3:","3","3","3","3","3","3","3","3","3","3","3","3","3","3","2","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","0","0","0","0","0","0","2:","2:","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2:","2:","2:","2:","2:","2:","2:","2:","2","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2"
};

const std::vector<std::string> LevelManager::Level_1::Level_1_Map_3
{
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2",
    "2","2","2","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2","2","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","3:","3","3","3:","0","0","1","0","1","1","1","0","0","1","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","3:","3","3","3:","0","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0p","0","1","0","0","0","3:","3:","3:","3:","7","7","0","0","0","1","1","1","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","5:","6:","0","7","0","1","0","0","0","1","1","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","1","0","0","0","0","0","0","1","0","5:","5:","7","7","0","0","0","0","1","0","0","1","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","6:","5:","0","0","7","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","0","0","0","7","0","7","0","0","1","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","0","0f","7","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","0","0","7","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","5:","6:","5:","5:","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2","5","5","6","5","5","5","5","5","5","5","5","6","5","5","5","5","5","5:","0","0","1","0","0","1","0","0","2:","2","2","2","2","2",
    "2","2","2","2","5","5","5","5","5","5","6","5","6","5","5","5","5","6","5","5","5","5:","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2","6","5","5","5","5","5","5","5","5","5","5","5","5","5","5","5","5","5:","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","5:","5:","5:","5:","5:","6:","5:","5:","5:","5:","5:","6:","5:","5:","5:","5:","5:","5:","0","0f","0","0","1","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","1","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","1","1","1","0","0","0","0","0","0","0","1","0","0","0","0","0","0","0","0","0","1","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","1c","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0f","0","1","0","0","0","0","0","0","3:","3","3","3","3","3","3","3","3","3","3","3","3","3","3","2","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","3:","3","3","3","3","3","3","3","3","3","3","3","3","3","3","2","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","3:","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1","0","0","0","0","0","0f","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","2:","2","2","2","2","2",
    "2","2","2","2:","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0x","0x","0x","0x","0x","0x","0","2:","2","2","2","2","2",
    "2","2","2","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","2:","0x","0x","0x","0x","0x","0x","2:","2:","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2:","2:","2:","2:","2:","2:","2:","2:","2","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2",
    "2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2"
};