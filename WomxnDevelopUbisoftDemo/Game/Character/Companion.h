#pragma once

class Companion : public Character
{
public:
	Companion(Character&, const std::string&);
	void Update(float) override;

	bool IsCloseToLeader() const;
	bool DetectsLeader() const;
	bool IsAttached() const;

	void PetTheCompanion();
	void HealLeader();

	void onCollision(const BoxCollideable&) override;
	void CollidesRigidBody() override;

	const double getDistanceToLeader() const { return m_DistanceToLeader; };

protected:
private:
	Character& m_Leader;
	bool m_IsAttachedToLeader;
	double m_DistanceToLeader;
	float m_DetectionDistance;
	float m_FollowDistance;

	sf::SoundBuffer m_WoofSoundBuffer;
	sf::Sound m_WoofSound;

	sf::SoundBuffer m_MlemSoundBuffer;
	sf::Sound m_MlemSound;
};