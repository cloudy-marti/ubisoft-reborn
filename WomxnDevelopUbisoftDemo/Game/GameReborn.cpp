#include "stdafx.h"

GameReborn::GameReborn()
    : Game{ "Reborn" }
    , m_MainCharacter{ ".\\Assets\\character\\issou.png" }
    , m_Companion{ m_MainCharacter, ".\\Assets\\character\\pup.bmp" }
    , m_MainCamera{ m_Window.getDefaultView() }
{
    m_EndgameTextFont.loadFromFile("Assets\\arial.ttf");

    m_EndgameText.setFont(m_EndgameTextFont);
    m_EndgameText.setPosition(0, 0);
    m_EndgameText.setString("!!! WIN !!!");
    m_EndgameText.setCharacterSize(24);
    m_EndgameText.setFillColor(sf::Color::Red);

    m_EndgameSoundBuffer.loadFromFile("Assets\\sound\\Test.wav");
    m_EndgameSound.setBuffer(m_EndgameSoundBuffer);

    m_Window.setView(m_MainCamera.getView());

    m_LevelManager->Start(m_MainCharacter, m_Companion, m_Enemies, m_Checkpoints, m_Map);
}

GameReborn::~GameReborn()
{}

void GameReborn::Update(float deltaTime)
{
    if (!m_HasStarted || m_OnPause)
    {
        if (m_UIManager->HasClickedStart() && !m_UIManager->IsPlayingStartMusic())
        {
            m_HasStarted = true;
            m_Music.play();
        }
        return;
    }

    m_InputManager->Update();

    // update characters position
    m_MainCharacter.Update(deltaTime);
    m_Companion.Update(deltaTime);

    m_PhysicsManager->Update();

    for (Foe* enemy : m_Enemies)
    {
        enemy->Update(deltaTime);
    }

    // update camera following the main character
    if(m_MainCharacter.IsCameraSafe())
    {
        m_MainCamera.setCenter(m_MainCharacter.GetCenter());
        m_Window.setView(m_MainCamera.getView());
    }

    m_LevelManager->LoadLevels(m_MainCharacter, m_Companion, m_Enemies, m_Checkpoints, m_Map);
    if (m_LevelManager->m_EndGame)
    {
        StartEndGame();
    }

    m_Enemies.erase(std::remove_if(m_Enemies.begin(), m_Enemies.end(), [](Foe* f) { return f->IsDead(); }), m_Enemies.end());
}

void GameReborn::StartEndGame()
{
    if (!m_IsFinished)
    {
        sf::Vector2f position = m_MainCharacter.GetCenter();
        m_EndgameText.setPosition(position.x, position.y - 80.f);
        m_IsFinished = true;
        m_EndgameSound.play();
        m_Enemies.clear();
    }
}

void GameReborn::Render(sf::RenderTarget& target)
{
    target.clear(sf::Color(0, 0, 0));

    if (m_UIManager->IsPlayingStartMusic())
    {
        m_UIManager->RenderDialogueBox("You", "...!!?");
        return;
    }
    if (!m_HasStarted)
    {
        return;
    }

    target.draw(m_Map);

    target.draw(m_Companion);
    target.draw(m_MainCharacter);

    for (Foe* enemy : m_Enemies)
    {
        target.draw(*enemy);
    }

     //for debug only
    for (auto wall : m_Map.getWalls())
    {
        target.draw(*wall);
    }

    if (m_IsFinished)
    {
        target.draw(m_EndgameText);
    }
}
