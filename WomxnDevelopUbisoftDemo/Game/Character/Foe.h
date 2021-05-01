#pragma once
#include "Follower.h"
class Foe : public Follower
{
public:
	Foe(sf::Vector2f position, Character& leader, const std::string& filePath);

	void onCollision(const BoxCollideable&) override;
	void Die() override;

	void ActionCloseToLeader() override;
	void ActionLeaderDetected() override;

	inline bool IsDead() const { return m_Dead; }

private:
	bool m_Dead = false;

	sf::SoundBuffer m_SwordSwingBuffer;
	sf::Sound m_SwordSwingSound;
};
