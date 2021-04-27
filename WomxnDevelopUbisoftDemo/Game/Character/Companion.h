#pragma once

#include "Follower.h"

class Companion : public Follower
{
public:
	Companion(Character&, const std::string&);

	void HealLeader();

	void Die() override;

	inline void ActionCloseToLeader() override { return; }
	inline void ActionLeaderDetected() override { m_IsAttachedToLeader = true; }

	void onCollision(const BoxCollideable&) override;

protected:
private:
	sf::SoundBuffer m_WoofSoundBuffer;
	sf::Sound m_WoofSound;

	sf::SoundBuffer m_MlemSoundBuffer;
	sf::Sound m_MlemSound;
};