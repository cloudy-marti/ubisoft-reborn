#include <stdafx.h>
#include <string>

Companion::Companion(Character& leader, const std::string& filePath)
	: Character{ { 800.f, 250.f }, .5f, 3.f, 5.f, 3.f, filePath, BoxCollideable::Tag::COMPANION }
	, m_Leader				{ leader }
	, m_IsAttachedToLeader	{ false }
	, m_DistanceToLeader	{ getDistance(leader.GetCenter(), GetCenter()) }
	, m_DetectionDistance	{ 300.f }
	, m_FollowDistance		{ 50.f }
{
	InputManager* inputManager = InputManager::GetInstance();
	inputManager->BindKey(sf::Keyboard::Space, *this, &Companion::PetTheCompanion);
	inputManager->BindKey(sf::Keyboard::A, *this, &Companion::HealLeader);

	m_BoundingBox.BindOnCollisionFunc(*this, &Companion::onCollision);

	m_WoofSoundBuffer.loadFromFile("Assets\\sound\\wowo.wav");
	m_WoofSound.setBuffer(m_WoofSoundBuffer);
}

void Companion::Update(float deltaTime)
{
	m_DistanceToLeader = getDistance(m_Leader.GetCenter(), GetCenter());
	if (!DetectsLeader())
	{
		m_IsAttachedToLeader = false;
		return;
	}
	m_IsAttachedToLeader = true;
	if (IsCloseToLeader())
	{
		return;
	}

	sf::Vector2f leaderPosition = m_Leader.GetCenter();

	m_Velocity.x = leaderPosition.x - m_Position.x;
	m_Velocity.y = leaderPosition.y - m_Position.y;

	//m_Velocity.x *= SLOWDOWN_RATE;
	//m_Velocity.y *= SLOWDOWN_RATE;

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

bool Companion::IsCloseToLeader() const
{
	return m_DistanceToLeader < m_FollowDistance;
}

bool Companion::DetectsLeader() const
{
	return m_DistanceToLeader < m_DetectionDistance;
}

bool Companion::IsAttached() const
{
	return m_IsAttachedToLeader;
}

void Companion::PetTheCompanion()
{
	if (IsCloseToLeader())
	{
		m_WoofSound.play();
	}
}

void Companion::HealLeader()
{
	if (IsCloseToLeader())
	{
		m_Leader.Heal(.5f);
	}
}

void Companion::onCollision(const BoxCollideable& other)
{
	BoxCollideable::Tag tag = other.getTag();

	switch (tag)
	{
	case BoxCollideable::Tag::PLAYER:
	{
		CollidesRigidBody();
		break;
	}
	case BoxCollideable::Tag::ENEMY:
		break;
	case BoxCollideable::Tag::WALL:
	{
		CollidesRigidBody();
		break;
	}
	case BoxCollideable::Tag::COMPANION:
	default:
		break;
	}
}

void Companion::CollidesRigidBody()
{
	Character::CollidesRigidBody();
}
