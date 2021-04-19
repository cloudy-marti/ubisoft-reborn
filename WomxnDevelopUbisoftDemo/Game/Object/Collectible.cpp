#include "stdafx.h"
#include "Collectible.h"

Collectible::Collectible(sf::Vector2f position, sf::Vector2f velocity, const std::string& filePath, float timeToLive, BoxCollideable::Tag tag)
	: m_Position { position }
	, m_Velocity { velocity }
	, m_TimeToLive { timeToLive }
{
	m_Texture.loadFromFile(filePath);

	const sf::Vector2f textureSize(static_cast<float>(m_Texture.getSize().x), static_cast<float>(m_Texture.getSize().y));
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setOrigin(textureSize * .5f);
	m_Sprite.setPosition(m_Position);
	m_Sprite.setScale({ 1.f, 1.f });

	m_BoundingBox.setTag(tag);
	m_BoundingBox.SetBoundingBox(m_Position, textureSize * 1.f);
	m_BoundingBox.BindOnCollisionFunc(*this, &Collectible::onCollision);
}

void Collectible::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Sprite);
}

void Collectible::Update(float deltaTime)
{
	m_TimeToLive -= deltaTime;
	if (m_TimeToLive < 0.f)
	{
		m_Disappeared = true;
	}

	m_Position += m_Velocity;
	m_Sprite.setPosition(m_Position);
	m_BoundingBox.SetCenter(m_Position);
}
