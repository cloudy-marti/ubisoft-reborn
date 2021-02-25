#include "stdafx.h"
#include "GameDemo.h"

GameDemo::GameDemo()
    : Game{ "Game Demo" }
    , m_Door{ 900, 600, 100, 200 }
    , m_MainCharacter{ ".\\Assets\\red_ball.bmp" }
    , m_Camera{ m_Window.getDefaultView() }
    , m_IsFinished{ false }
{
    m_EndgameTextFont.loadFromFile("Assets\\arial.ttf");

    m_EndgameText.setFont(m_EndgameTextFont);
    m_EndgameText.setPosition(500, 400);
    m_EndgameText.setString("!!! WIN !!!");
    m_EndgameText.setCharacterSize(24);
    m_EndgameText.setFillColor(sf::Color::Red);

    m_EndgameSoundBuffer.loadFromFile("Assets\\Test.wav");

    m_EndgameSound.setBuffer(m_EndgameSoundBuffer);

    m_Window.setView(m_Camera);
}

GameDemo::~GameDemo()
{
    for (Wall* w : m_Walls)
    {
        delete w;
    }
}

#include <iostream>

void GameDemo::Update(float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
    {
        std::cout << "zoom in" << std::endl;
        m_Camera.zoom(0.9f);
        m_Window.setView(m_Camera);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
    {
        std::cout << "zoom out" << std::endl;
        m_Camera.zoom(1.1f);
        m_Window.setView(m_Camera);
    }

    for (Wall* w : m_Walls)
    {
        if (w->IsColliding(m_MainCharacter))
        {
            m_MainCharacter.CollidesWall();
        }
    }

    m_MainCharacter.Update(deltaTime);
    m_Camera.setCenter(m_MainCharacter.GetCenter());
    m_Window.setView(m_Camera);

    m_Door.Update(deltaTime);

    if (!m_IsFinished)
    {
        //if (m_Door.IsColliding(m_MainCharacter))
        //if (m_Door.Contains(m_MainCharacter.GetCenter()))
        if (m_Door.Contains(m_MainCharacter))
        {
            m_EndgameSound.play();

            m_MainCharacter.StartEndGame();
            m_Door.StartEndGame();
            m_IsFinished = true;
        }
    }
}

void GameDemo::Render(sf::RenderTarget& target)
{
    target.clear(sf::Color(0, 0, 0));
    target.draw(m_Door);
    target.draw(m_MainCharacter);
    //target.draw(m_Wall);

    for(Wall* w : m_Walls)
    {
        target.draw(*w);
    }

    if (m_IsFinished)
    {
        target.draw(m_EndgameText);
    }
}

void GameDemo::RenderDebugMenu(sf::RenderTarget& target)
{
    ImGui::Begin("Debug Menu");
    ImGui::Text("Press F1 to close this debug menu");
    ImGui::NewLine();

    if (ImGui::CollapsingHeader("Main character position"))
    {
        const auto& mainCharCenterPos = m_MainCharacter.GetCenter();

        ImGui::Text("X: %f", mainCharCenterPos.x);
        ImGui::Text("Y: %f", mainCharCenterPos.y);
    }

    if (ImGui::CollapsingHeader("2D Camera status"))
    {
        const auto& cameraCenterPos = m_Camera.getCenter();
        const auto& windowViewCenterPos = m_Window.getView().getCenter();
        const auto& windowDefaultViewCenterPos = m_Window.getDefaultView().getCenter();

        ImGui::Text("Camera");
        ImGui::Text("X: %f", cameraCenterPos.x);
        ImGui::Text("Y: %f\n", cameraCenterPos.y);

        ImGui::Text("Current View");
        ImGui::Text("X: %f", windowViewCenterPos.x);
        ImGui::Text("Y: %f\n", windowViewCenterPos.y);

        ImGui::Text("Default View");
        ImGui::Text("X: %f", windowDefaultViewCenterPos.x);
        ImGui::Text("Y: %f\n", windowDefaultViewCenterPos.y);
    }

    if (ImGui::CollapsingHeader("Game status"))
    {
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

void GameDemo::addWall(float xCenterPos, float yCenterPos, float width, float height)
{
    m_Walls.emplace_back(new Wall{ xCenterPos, yCenterPos, width, height });
}

