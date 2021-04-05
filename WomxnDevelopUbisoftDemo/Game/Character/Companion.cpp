#include <stdafx.h>

Companion::Companion(Character& leader, const std::string& filePath)
	: Follower{ { 900.f, 400.f }, 150.f, 3.f, 5.f, 3.f, filePath, BoxCollideable::Tag::COMPANION
				, leader, 300.f, 50.f }
{
	InputManager* inputManager = InputManager::GetInstance();
	inputManager->BindKey(sf::Keyboard::Space, sf::Keyboard::Space, sf::Keyboard::Space, *this, &Companion::PetTheCompanion);
	inputManager->BindKey(sf::Keyboard::A, sf::Keyboard::Q, sf::Keyboard::A, *this, &Companion::HealLeader);

	m_BoundingBox.BindOnCollisionFunc(*this, &Companion::onCollision);

	m_WoofSoundBuffer.loadFromFile("Assets\\sound\\wowo.wav");
	m_WoofSound.setBuffer(m_WoofSoundBuffer);

	m_MlemSoundBuffer.loadFromFile("Assets\\sound\\mlem.wav");
	m_MlemSound.setBuffer(m_MlemSoundBuffer);
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
	if (IsCloseToLeader() && !m_OnCoolDown)
	{
		m_OnCoolDown = true;
		m_MlemSound.play();
		m_Leader.Heal(1.f);
	}
}

void Companion::Die()
{
	m_Position = m_LastCheckPoint;
	m_HealthPoints = m_MaxHealthPoints;
}

void Companion::onCollision(const BoxCollideable& other)
{
	BoxCollideable::Tag tag = other.getTag();

	switch (tag)
	{
	case BoxCollideable::Tag::PLAYER:
	{
		//CollidesRigidBody();
		break;
	}
	case BoxCollideable::Tag::ENEMY:
		break;
	case BoxCollideable::Tag::WALL:
	{
		CollidesRigidBody();
		break;
	}
	case BoxCollideable::Tag::CHECKPOINT:
	{
		m_LastCheckPoint = other.GetCenter();
		break;
	}
	case BoxCollideable::Tag::COMPANION:
	default:
		break;
	}
}

//void Companion::CollidesRigidBody()
//{
//	Character::CollidesRigidBody();
//}
