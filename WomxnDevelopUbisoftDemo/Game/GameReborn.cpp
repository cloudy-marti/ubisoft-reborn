#include "stdafx.h"

GameReborn::GameReborn()
    : Game{ "Reborn" }
    //, m_Door{ 900, 600, 100, 200 }
    , m_MainCharacter{ ".\\Assets\\character\\issoucrusade.bmp" }
    , m_Companion{ m_MainCharacter, ".\\Assets\\character\\pup.bmp" }
    , m_MainCamera{ m_Window.getDefaultView() }
    , m_IsFinished{ false }
{
    m_EndgameTextFont.loadFromFile("Assets\\arial.ttf");

    m_EndgameText.setFont(m_EndgameTextFont);
    m_EndgameText.setPosition(500, 400);
    m_EndgameText.setString("!!! WIN !!!");
    m_EndgameText.setCharacterSize(24);
    m_EndgameText.setFillColor(sf::Color::Red);

    //m_EndgameSoundBuffer.loadFromFile("Assets\\sound\\Test.wav");

    //m_EndgameSound.setBuffer(m_EndgameSoundBuffer);

    m_Window.setView(m_MainCamera.getView());

    //m_Map = m_LevelManager->LoadFirstLevel(m_MainCharacter, m_Companion, m_Enemies);
    m_Map = m_LevelManager->LoadSecondLevel(m_MainCharacter, m_Companion, m_Enemies);
    //m_Map = m_LevelManager->LoadThirdLevel(m_MainCharacter, m_Companion, m_Enemies);
}

GameReborn::~GameReborn()
{}

void GameReborn::Update(float deltaTime)
{
    m_InputManager->Update();
    m_PhysicsManager->Update();
    m_LevelManager->Update();

    // update characters position
    m_MainCharacter.Update(deltaTime);
    m_Companion.Update(deltaTime);

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

    //m_Door.Update(deltaTime);

    //if (m_Door.IsEndGame())
    //{
    //    m_EndgameSound.play();

    //    m_MainCharacter.StartEndGame();
    //    m_IsFinished = true;
    //}
}

void GameReborn::Render(sf::RenderTarget& target)
{
    target.clear(sf::Color(0, 0, 0));
    target.draw(m_Map);
    //target.draw(m_Door);

    for (Foe* enemy : m_Enemies)
    {
        target.draw(*enemy);
    }

    target.draw(m_Companion);
    target.draw(m_MainCharacter);
    //const std::vector<CollideableObject*> walls = m_Map.getWalls();

    //for(CollideableObject* w : walls)
    //{
    //    target.draw(*w);
    //}

    if (m_IsFinished)
    {
        target.draw(m_EndgameText);
    }
}

#include <numeric>
void GameReborn::RenderDebugMenu(sf::RenderTarget& target)
{
    ImGui::Begin("Debug Menu");
    ImGui::Text("Press F1 to close this debug menu");
    ImGui::NewLine();

    const auto& mainCharCenterPos = m_MainCharacter.GetCenter();
    const auto& charCenterPos = m_Companion.GetCenter();
    
    if (ImGui::CollapsingHeader("Main character status"))
    {
        ImGui::Text("X: %f", mainCharCenterPos.x);
        ImGui::Text("Y: %f", mainCharCenterPos.y);

        ImGui::Text("HP: %f", m_MainCharacter.GetHP());
    }

    if (ImGui::CollapsingHeader("Companion status"))
    {
        ImGui::Text("X: %f", charCenterPos.x);
        ImGui::Text("Y: %f", charCenterPos.y);

        ImGui::Text("Attached: %s", m_Companion.IsAttached() ? "yes" : "no");
        ImGui::Text("Distance from leader: %f", m_Companion.getDistanceToLeader());

        ImGui::Text("HP: %f", m_Companion.GetHP());

        if (m_Companion.IsOnCoolDown()) { ImGui::Text(m_Companion.GetCoolDown().c_str()); }
    }

    if (ImGui::CollapsingHeader("Enemies status"))
    {
        ImGui::Text("Enemies on map: %d", m_Enemies.size());
    }

    if (ImGui::CollapsingHeader("2D Camera status"))
    {
        const auto& cameraCenterPos = m_MainCamera.getCenter();
        const auto& windowViewCenterPos = m_Window.getView().getCenter();
        const auto& windowDefaultViewCenterPos = m_Window.getDefaultView().getCenter();

        ImGui::Text("Camera");
        ImGui::Text("X: %f", cameraCenterPos.x);
        ImGui::Text("Y: %f\n", cameraCenterPos.y);

        ImGui::Text("Current View");
        ImGui::Text("X: %f", windowViewCenterPos.x);
        ImGui::Text("Y: %f\n", windowViewCenterPos.y);
    }

    if (ImGui::CollapsingHeader("Game status"))
    {
        ImGui::Text("Keyboard Layout: %s", m_InputManager->GetKeyboardLayout().c_str());
        if (m_IsFinished)
        {
            ImGui::TextColored(ImVec4(255.f, 0.f, 0.f, 1.f), "GAME ENDED");
        }
        else
        {
            ImGui::TextColored(ImVec4(0.f, 255.0f, 0.f, 1.f), "GAME IN PROGRESS");
        }
    }

    ImGui::End();
}
