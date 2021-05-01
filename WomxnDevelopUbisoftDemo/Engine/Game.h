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
    virtual void RenderStartMenu(sf::RenderTarget& target) = 0;
    virtual void RenderDebugMenu(sf::RenderTarget& target) = 0;
    virtual void RenderDialogueBox(sf::RenderTarget&, const std::string&, const std::string&) = 0;

    inline void PauseGame() { m_OnPause = true; }
    inline void UnpauseGame() { m_OnPause = false; }
    inline void TogglePause() { m_OnPause = !m_OnPause; }

    bool m_ToggleDialogue = false;

    sf::RenderWindow m_Window;

    InputManager*   m_InputManager;
    PhysicsEngine*  m_PhysicsManager;
    LevelManager*   m_LevelManager;

    bool m_HasStarted = false;
    bool m_IsFinished = false;
    bool m_OnPause = false;
    bool m_ToggleHelp = true;

private:
};