#pragma once

class UIManager
{
public:
	static UIManager* GetInstance();

	void Update(float);

	void RenderStartMenu();
	void RenderDebugMenu();
	void RenderDialogueBox(const std::string&, const std::string&);

	inline bool shouldGameBePaused()
	{
		return m_BlockingEvent;
	}
	inline bool HasClickedStart() const { return m_StartClicked; }
	inline bool IsPlayingStartMusic() const { return m_EarthquakeSound.getStatus() == sf::SoundSource::Status::Playing; }

private:
	static UIManager* _Instance;

	UIManager()
	{
		m_EarthquakeBuffer.loadFromFile("Assets\\sound\\earthquakewoof.wav");
		m_EarthquakeSound.setBuffer(m_EarthquakeBuffer);
	}

	sf::SoundBuffer m_EarthquakeBuffer;
	sf::Sound m_EarthquakeSound;

	bool m_BlockingEvent = false;
	bool m_StartClicked = false;
};