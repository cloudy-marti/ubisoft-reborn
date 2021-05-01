#include "stdafx.h"

GameReborn::GameReborn()
    : Game{ "Reborn" }
    , m_MainCharacter{ ".\\Assets\\character\\issoucrusade.bmp" }
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

    m_EarthquakeBuffer.loadFromFile("Assets\\sound\\earthquakewoof.wav");
    m_EarthquakeSound.setBuffer(m_EarthquakeBuffer);

    m_Window.setView(m_MainCamera.getView());

    m_LevelManager->Start(m_MainCharacter, m_Companion, m_Enemies, m_Checkpoints, m_Map);
}

GameReborn::~GameReborn()
{}

void GameReborn::Update(float deltaTime)
{
    if (!m_HasStarted || m_OnPause)
    {
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

    m_LevelManager->LoadFirstLevel(m_MainCharacter, m_Companion, m_Enemies, m_Checkpoints, m_Map);
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

    if (!m_HasStarted)
    {
        return;
    }
    if (m_EarthquakeSound.getStatus() == sf::SoundSource::Status::Playing)
    {
        m_ToggleDialogue = true;
        RenderDialogueBox(m_Window, "You", "...!!?");
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

void GameReborn::RenderStartMenu(sf::RenderTarget&)
{
    ImGui::SetNextWindowPos({ (1024/2)-50, (768/2)-50 });
    ImGui::Begin("start", &m_HasStarted, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar);
    if (ImGui::Button("START GAME"))
    {
        m_EarthquakeSound.play();
        m_HasStarted = !m_HasStarted;
    }
    ImGui::End();
}

void GameReborn::RenderDebugMenu(sf::RenderTarget&)
{
    ImGui::Begin("Help");
    ImGui::Text("Press F1 to close this help menu");
    ImGui::NewLine();

    const auto& mainCharCenterPos = m_MainCharacter.GetCenter();
    const auto& charCenterPos = m_Companion.GetCenter();

    if (!m_ToggleHelp)
    {
        ImGui::End();
        return;
    }

    if (ImGui::CollapsingHeader("Inputs"))
    {
        ImGui::Text("Keyboard Layout: %s (toggle with F3)", m_InputManager->GetKeyboardLayout().c_str());
        ImGui::Text("Walk with WASD/ZQSD/Arrows");
        ImGui::Text("A: Companion heals");
        ImGui::Text("Space: Companion barks (useless)");
        ImGui::Text("+/-: Zoom in / Zoom out");
    }
    
    if (ImGui::CollapsingHeader("Main character status"))
    {
        ImGui::Text("X: %f", mainCharCenterPos.x);
        ImGui::Text("Y: %f", mainCharCenterPos.y);

        ImGui::Text("HP: %f", m_MainCharacter.GetHP());
        ImGui::Text("Has sword: %s", m_MainCharacter.HasSword() ? "yes" : "no");
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

        ImGui::Text("Camera");
        ImGui::Text("X: %f", cameraCenterPos.x);
        ImGui::Text("Y: %f\n", cameraCenterPos.y);

        ImGui::Text("Current View");
        ImGui::Text("X: %f", windowViewCenterPos.x);
        ImGui::Text("Y: %f\n", windowViewCenterPos.y);
    }

    if (ImGui::CollapsingHeader("Game status"))
    {
        ImGui::Text("Game Paused: %s", m_OnPause? "yes" : "no");

        ImGui::Text("Level: %d", m_LevelManager->m_Level);
        
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

void GameReborn::RenderDialogueBox(sf::RenderTarget&, const std::string& title, const std::string& text)
{
    ImGui::SetNextWindowSize({1024, 200});
    ImGui::SetNextWindowPos({ 0, 560 });
    ImGui::Begin(title.c_str(), &m_ToggleDialogue, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoMove);
    ImGui::Text(text.c_str());
    ImGui::End();
}
