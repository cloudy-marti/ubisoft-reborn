#pragma once

class GameReborn : public Game
{
public:
    GameReborn();
    ~GameReborn();

    void Update(float deltaTime) override;

    void StartEndGame();

    void Render(sf::RenderTarget& target) override;
    void RenderDebugMenu(sf::RenderTarget& target) override;

private:

    sf::Font m_EndgameTextFont;
    sf::Text m_EndgameText;

    sf::SoundBuffer m_EndgameSoundBuffer;
    sf::Sound m_EndgameSound;

    TileMap m_Map;

    MainCharacter m_MainCharacter;
    Companion m_Companion;
    std::vector<Foe*> m_Enemies{};

    std::vector<Checkpoint*> m_Checkpoints{};

    Camera m_MainCamera;

    bool m_IsFinished = false;
};