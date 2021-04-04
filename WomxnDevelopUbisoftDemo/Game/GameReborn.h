#pragma once

#include <vector>

#include <Engine/Game.h>
#include <Game/Object/Checkpoint.h>
#include <Game/Character/MainCharacter.h>
#include <Game/Character/Companion.h>
#include <Game/Object/CollideableObject.h>
#include <Engine/Camera.h>
#include <Engine/Level/TileMap.h>

class GameReborn : public Game
{
public:
    GameReborn();
    ~GameReborn();

    void Update(float deltaTime) override;

    void Render(sf::RenderTarget& target) override;
    void RenderDebugMenu(sf::RenderTarget& target) override;

    void addAnNPC(Character*);

    //void addWall(float xCenterPos, float yCenterPos, float width, float height);

private:

    sf::Font m_EndgameTextFont;
    sf::Text m_EndgameText;

    sf::SoundBuffer m_EndgameSoundBuffer;
    sf::Sound m_EndgameSound;

    Checkpoint m_Door;

    TileMap m_Map;

    MainCharacter m_MainCharacter;
    Companion m_Companion;

    std::vector<Character*> m_Enemies;

    Camera m_MainCamera;

    bool m_IsFinished;
};