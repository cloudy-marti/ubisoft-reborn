#include <stdafx.h>
#include <string>

Companion::Companion(const Character& leader, const std::string& filePath)
	: Character{ { 800.f, 250.f }, .5f, 3,  filePath, BoxCollideable::Tag::COMPANION }
	, m_Leader				{ leader }
	, m_IsAttachedToLeader	{ false }
	, m_Distance			{ 30.f }
{
	InputManager* inputManager = InputManager::GetInstance();
	inputManager->BindKey(sf::Keyboard::Space, *this, &Companion::ToggleLeaderAttachment);

	m_BoundingBox.BindOnCollisionFunc(*this, &Companion::onCollision);

	m_WoofSoundBuffer.loadFromFile("Assets\\sound\\wowo.wav");
	m_WoofSound.setBuffer(m_WoofSoundBuffer);
}

#include <iostream>
void Companion::Update(float deltaTime)
{
	if (!m_IsAttachedToLeader)
	{
		return;
	}
	else
	{
		// TODO
	}
}

#include <math.h>
double getDistance(sf::Vector2f first, sf::Vector2f second)
{
	return pow(pow(first.x - second.x, 2) + pow(first.y - second.y, 2), 0.5);
}

bool Companion::IsNearLeader() const
{
	return getDistance(m_Leader.GetCenter(), GetCenter()) < m_Distance;
}

bool Companion::IsAttached() const
{
	return m_IsAttachedToLeader;
}

void Companion::ToggleLeaderAttachment()
{
	if (m_IsAttachedToLeader)
	{
		return;
	}
	m_IsAttachedToLeader = !m_IsAttachedToLeader;
	m_WoofSound.play();
}

void Companion::onCollision(const BoxCollideable& other)
{
	BoxCollideable::Tag tag = other.getTag();

	switch (tag)
	{
	case BoxCollideable::Tag::PLAYER:
		std::cout << "hello !" << std::endl;
		break;
	case BoxCollideable::Tag::ENEMY:
		break;
	case BoxCollideable::Tag::WALL:
	{
		CollidesWall();
		break;
	}
	case BoxCollideable::Tag::COMPANION:
	default:
		break;
	}
}