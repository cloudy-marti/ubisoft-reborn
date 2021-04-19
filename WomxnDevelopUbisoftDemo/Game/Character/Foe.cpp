#include "stdafx.h"

Foe::Foe(sf::Vector2f position, Character& leader, const std::string& filePath)
	: Follower { position, 100.f, 1.f, 1.f, 1.5f, filePath, BoxCollideable::Tag::ENEMY, leader, 150.f, 30.f }
{
	m_BoundingBox.BindOnCollisionFunc(*this, &Foe::onCollision);

	m_SwordSwingBuffer.loadFromFile("Assets\\sound\\sword_swing.wav");
	m_SwordSwingSound.setBuffer(m_SwordSwingBuffer);
}

void Foe::onCollision(const BoxCollideable& other)
{
	BoxCollideable::Tag tag = other.getTag();

	switch (tag)
	{
	case BoxCollideable::Tag::PLAYER:
	case BoxCollideable::Tag::COMPANION:
		ActionCloseToLeader();
		break;
	case BoxCollideable::Tag::WALL:
		CollidesRigidBody();
		break;
	case BoxCollideable::Tag::DAMAGING_OBJECT:
		TakeDamage(1.5f);
	default:
		break;
	}
}

void Foe::Die()
{
	m_Dead = true;
}

void Foe::ActionCloseToLeader()
{
	if (IsCloseToLeader() && !m_OnCoolDown)
	{
		m_OnCoolDown = true;
		m_SwordSwingSound.play();
		m_Leader.TakeDamage(1.5f);
	}
}

void Foe::ActionLeaderDetected()
{
	m_IsAttachedToLeader = true;
}
