#include <stdafx.h>
#include <string>

Companion::Companion(const Character& leader, const std::string& filePath)
	: Character{ { 800.f, 250.f }, 3,  filePath }
	, m_Leader				{ leader }
	, m_IsAttachedToLeader	{ false }
	, m_Distance			{ m_BoundingBox.width }
{
	InputManager* inputManager = InputManager::GetInstance();
	inputManager->BindKey(sf::Keyboard::Enter, *this, &Companion::AttachToLeader);
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
		std::cout << "hello !" << std::endl;
	}
}

#include <math.h>
float getDistance(sf::Vector2f first, sf::Vector2f second)
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

void Companion::CollidesLeader(float deltaTime) const
{
	
}

void Companion::AttachToLeader()
{
	m_IsAttachedToLeader = true;
}

void Companion::DetachFromLeader()
{
	m_IsAttachedToLeader = false;
}
