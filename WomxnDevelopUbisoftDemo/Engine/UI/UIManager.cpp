#include <stdafx.h>

UIManager* UIManager::_Instance = nullptr;

UIManager* UIManager::GetInstance()
{
    if (_Instance == nullptr)
    {
        _Instance = new UIManager();
    }
    return _Instance;
}

void UIManager::Update(float)
{

}

void UIManager::RenderStartMenu()
{
    ImGui::SetNextWindowSize({300, 300});
    ImGui::SetNextWindowPos({ (1024 / 2) - 50, (768 / 2) - 50 });
    ImGui::Begin("start", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar);
    if (ImGui::Button("START GAME"))
    {
        m_StartClicked = true;
        m_EarthquakeSound.play();
    }
    ImGui::End();
}

void UIManager::RenderDialogueBox(const std::string& title, const std::string& text)
{
    ImGui::SetNextWindowSize({ 1024, 200 });
    ImGui::SetNextWindowPos({ 0, 560 });
    ImGui::Begin(title.c_str(), &m_BlockingEvent, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoMove);
    ImGui::Text(text.c_str());
    ImGui::End();
}

void UIManager::RenderDebugMenu()
{
    ImGui::Begin("Help");
    ImGui::Text("Find your friend and escape from this unknown place!");
    ImGui::NewLine();

    if (ImGui::CollapsingHeader("Inputs"))
    {
        ImGui::Text("Keyboard Layout: %s (toggle with F3)", InputManager::GetInstance()->GetKeyboardLayout().c_str());
        ImGui::NewLine();
        ImGui::Text("A: Companion heals");
        ImGui::NewLine();
        ImGui::Text("Space: Attack with sword");
        ImGui::NewLine();
        ImGui::Text("+/-: Zoom in / Zoom out");
    }
    /*const auto& mainCharCenterPos = m_MainCharacter.GetCenter();
    const auto& charCenterPos = m_Companion.GetCenter();

    if (!m_ToggleHelp)
    {
        ImGui::End();
        return;
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
        ImGui::Text("Game Paused: %s", m_OnPause ? "yes" : "no");

        ImGui::Text("Level: %d", m_LevelManager->m_Level);

        if (m_IsFinished)
        {
            ImGui::TextColored(ImVec4(255.f, 0.f, 0.f, 1.f), "GAME ENDED");
        }
        else
        {
            ImGui::TextColored(ImVec4(0.f, 255.0f, 0.f, 1.f), "GAME IN PROGRESS");
        }
    }*/

    ImGui::End();
}

