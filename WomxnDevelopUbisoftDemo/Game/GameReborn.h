#pragma once

class GameReborn : public Game
{
public:
    GameReborn();
    ~GameReborn();

    void Update(float deltaTime) override;

    void StartEndGame();

    void Render(sf::RenderTarget& target) override;
    void RenderStartMenu(sf::RenderTarget& target) override;
    void RenderDebugMenu(sf::RenderTarget& target) override;
    void RenderDialogueBox(sf::RenderTarget&, const std::string&, const std::string&) override;

private:
    sf::Font m_EndgameTextFont;
    sf::Text m_EndgameText;

    sf::SoundBuffer m_EndgameSoundBuffer;
    sf::Sound m_EndgameSound;

    sf::SoundBuffer m_EarthquakeBuffer;
    sf::Sound m_EarthquakeSound;

    TileMap m_Map;

    MainCharacter m_MainCharacter;
    Companion m_Companion;
    std::vector<Foe*> m_Enemies{};

    std::vector<Checkpoint*> m_Checkpoints{};

    Camera m_MainCamera;

    bool m_SoundPlaying = false;
    bool m_SoundPlayed = false;
};