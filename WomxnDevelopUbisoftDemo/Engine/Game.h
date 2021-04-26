#pragma once

#include <Engine/InputManager.h>
#include <Engine/Physics/PhysicsEngine.h>
#include <Engine/Level/LevelManager.h>

class Game
{
public:
    Game(const char* windowTitle);
    virtual ~Game();

    void RunGameLoop();

protected:
    virtual void Update(float deltaTime) = 0;
    virtual void Render(sf::RenderTarget& target) = 0;
    virtual void RenderDebugMenu(sf::RenderTarget& target) = 0;
    //virtual void PauseGame(float currentDeltaTime) = 0;

    sf::RenderWindow m_Window;

    InputManager*   m_InputManager;
    PhysicsEngine*  m_PhysicsManager;
    LevelManager*   m_LevelManager;

    bool m_OnPause = false;

private:
};