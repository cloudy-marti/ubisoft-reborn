#pragma once

#include "Character.h"

class Follower : public Character
{
public:
	virtual void Update(float deltaTime) override;
	
	virtual void Die() override = 0;
	virtual void onCollision(const BoxCollideable&) override = 0;

	inline bool IsCloseToLeader() const { return m_DistanceToLeader < m_FollowDistance; }
	inline bool DetectsLeader() const { return m_DistanceToLeader < m_DetectionDistance; }
	inline bool IsAttached() const { return m_IsAttachedToLeader; }

	virtual void ActionCloseToLeader() = 0;
	virtual void ActionLeaderDetected() = 0;

	inline const double getDistanceToLeader() const { return m_DistanceToLeader; };

protected:
	Follower(sf::Vector2f position, float factor, float hp, float max_hp, float cooldown, const std::string& filePath, BoxCollideable::Tag tag
		, Character& leader, const float detectionDistance, const float followDistance);
	
	Character& m_Leader;
	bool m_IsAttachedToLeader = false;
	double m_DistanceToLeader;
	const float m_DetectionDistance;
	const float m_FollowDistance;
};