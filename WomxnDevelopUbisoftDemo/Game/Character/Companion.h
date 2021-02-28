#pragma once

class Companion : public Character
{
public:
	Companion(const Character&, const std::string&);
	void Update(float) override;
	bool IsNearLeader() const;

	bool IsAttached() const;
	void ToggleLeaderAttachment();

	void onCollision(const BoxCollideable&) override;

protected:
private:
	const Character& m_Leader;
	bool m_IsAttachedToLeader;

	float m_Distance;

	sf::SoundBuffer m_WoofSoundBuffer;
	sf::Sound m_WoofSound;
};