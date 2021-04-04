#include "stdafx.h"

Follower::Follower(sf::Vector2f position, float factor, float hp, float max_hp, float cooldown, const std::string& filePath, BoxCollideable::Tag tag
	, Character& leader, const float detectionDistance, const float followDistance)
	: Character { position, factor, hp, max_hp, cooldown, filePath, tag }
	, m_Leader				{ leader }
	, m_DistanceToLeader	{ getDistance(leader.GetCenter(), GetCenter())  }
	, m_DetectionDistance	{ detectionDistance }
	, m_FollowDistance		{ followDistance }
{}

void Follower::Update(float deltaTime)
{
	if (m_OnCoolDown)
	{
		m_CurrentCoolDown -= deltaTime;
		if (m_CurrentCoolDown <= 0.f)
		{
			m_OnCoolDown = false;
			m_CurrentCoolDown = m_CoolDown;
		}
	}

	m_DistanceToLeader = getDistance(m_Leader.GetCenter(), GetCenter());
	if (!DetectsLeader())
	{
		m_IsAttachedToLeader = false;
		return;
	}

	ActionLeaderDetected();
	
	if (IsCloseToLeader())
	{
		ActionCloseToLeader();
		return;
	}

	sf::Vector2f leaderPosition = m_Leader.GetCenter();

	m_Velocity.x = leaderPosition.x - m_Position.x;
	m_Velocity.y = leaderPosition.y - m_Position.y;

	/* Normalize velocity and use speed_max */
	float vectorSize = pow(pow(m_Velocity.x, 2) + pow(m_Velocity.y, 2), 0.5);
	m_Velocity /= vectorSize;
	m_Velocity *= m_MaxSpeed;

	if (m_isCollidingRigidBody)
	{
		m_Position = m_OldPosition;
		m_isCollidingRigidBody = false;
	}
	else
	{
		m_OldPosition = m_Position;
		m_Position += m_Velocity * deltaTime;
	}

	m_Sprite.setPosition(m_Position);
	m_BoundingBox.SetCenter(m_Position);
	m_Velocity = { 0.f, 0.f };
}

