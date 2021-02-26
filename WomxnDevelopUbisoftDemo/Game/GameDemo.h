#pragma once

#include <vector>

#include <Engine/Game.h>
#include <Game/Door.h>
#include <Game/Character/MainCharacter.h>
#include <Game/Character/Companion.h>
#include <Game/Wall.h>

class GameDemo : public Game
{
public:
    GameDemo();
    ~GameDemo();

    void Update(float deltaTime) override;

    void Render(sf::RenderTarget& target) override;
    void RenderDebugMenu(sf::RenderTarget& target) override;

    void addAnNPC(Character*);
    void addWall(float xCenterPos, float yCenterPos, float width, float height);

private:
    sf::Font m_EndgameTextFont;
    sf::Text m_EndgameText;

    sf::SoundBuffer m_EndgameSoundBuffer;
    sf::Sound m_EndgameSound;

    Door m_Door;
    std::vector<Wall*> m_Walls;

    MainCharacter m_MainCharacter;
    Companion m_Companion;

    std::vector<Character*> m_Enemies;

    sf::View m_Camera;

    bool m_IsFinished;
};