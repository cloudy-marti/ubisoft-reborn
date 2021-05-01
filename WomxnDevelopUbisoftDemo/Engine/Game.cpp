#include <stdafx.h>

static constexpr float APP_MAX_FRAMERATE{ 60.0f };
static const sf::Vector2u APP_INIT_WINDOW_SIZE{ 1024, 768 };

Game::Game(const char* windowTitle)
    : m_Window{ sf::VideoMode(APP_INIT_WINDOW_SIZE.x, APP_INIT_WINDOW_SIZE.y), windowTitle, sf::Style::Titlebar | sf::Style::Close }
{
    m_Window.setVerticalSyncEnabled(true);
    m_Window.setFramerateLimit(static_cast<uint32_t>(APP_MAX_FRAMERATE));
    m_Window.setActive();
    ImGui::SFML::Init(m_Window);

    m_InputManager = InputManager::GetInstance();
    m_PhysicsManager = PhysicsEngine::GetInstance();
    m_LevelManager = LevelManager::GetInstance();
}

Game::~Game()
{
    ImGui::SFML::Shutdown();
}

void Game::RunGameLoop()
{
    float deltaTime{ 1.0f / APP_MAX_FRAMERATE };
    sf::Clock clock;

    while (m_Window.isOpen())
    {
        clock.restart();

        sf::Event event;
        while (m_Window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                {
                    m_Window.close();
                    break;
                }
                case sf::Event::KeyPressed:
                {
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        m_Window.close();
                    }
                    else if (event.key.code == sf::Keyboard::F1)
                    {
                        m_ToggleHelp = !m_ToggleHelp;
                    }
                    else if (event.key.code == sf::Keyboard::F3)
                    {
                        m_InputManager->ToggleKeyboardLayout();
                    }
                    else if (event.key.code == sf::Keyboard::P)
                    {
                        m_OnPause = !m_OnPause;
                    }
                    break;
                }
                case sf::Event::Resized:
                {
                    break;
                }
            }
            ImGui::SFML::ProcessEvent(event);
        }

        ImGui::SFML::Update(m_Window, clock.restart());

        if (!m_HasStarted)
        {
            RenderStartMenu(m_Window);
        }
        else
        {
            RenderDebugMenu(m_Window);
        }

        Update(deltaTime);
        Render(m_Window);

        ImGui::SFML::Render(m_Window);

        ImGui::EndFrame();

        m_Window.display();

        deltaTime = clock.getElapsedTime().asSeconds();
    }
}