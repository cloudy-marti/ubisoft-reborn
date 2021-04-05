#include "stdafx.h"

CollideableObject::CollideableObject(float xCenterPos, float yCenterPos, float width, float height)
	: m_rColor{ 0.8f }
	, m_gColor{ 0.5f }
	, m_bColor{ 1.0f }
	, m_BoundingBox { BoxCollideable::Tag::WALL }
{
	const auto center = sf::Vector2f(xCenterPos, yCenterPos);
	const auto size = sf::Vector2f(width, height);

	m_BoundingBox.SetBoundingBox(center, size);
	m_BoundingBox.BindOnCollisionFunc(*this, &CollideableObject::onCollision);

	m_Rectangle.setSize(size);
	m_Rectangle.setOrigin(size * 0.5f);
	m_Rectangle.setPosition(center);

	m_Rectangle.setFillColor(sf::Color{ static_cast<uint8_t>(m_rColor), static_cast<uint8_t>(m_gColor), static_cast<uint8_t>(m_bColor) });
	m_Rectangle.setOutlineThickness(1.f);
	m_Rectangle.setOutlineColor(sf::Color{ static_cast<uint8_t>(m_rColor * 255.0f), static_cast<uint8_t>(m_gColor * 255.0f), static_cast<uint8_t>(m_bColor * 255.0f) });
}

CollideableObject::CollideableObject(const CollideableObject& other)
	: m_rColor      { other.m_rColor }
	, m_gColor	    { other.m_gColor }
	, m_bColor	    { other.m_bColor }
	, m_Rectangle   { other.m_Rectangle }
	, m_BoundingBox { other.m_BoundingBox }
{}

CollideableObject::~CollideableObject()
{}

void CollideableObject::Update(float deltaTime)
{
	float colorDelta = 0.2f * deltaTime / 1000.0f;

	m_rColor = fmodf(m_rColor + colorDelta, 1.f);
	m_gColor = fmodf(m_gColor + colorDelta, 1.f);
	m_bColor = fmodf(m_bColor + colorDelta, 1.f);
	m_Rectangle.setOutlineColor(sf::Color{ static_cast<uint8_t>(m_rColor * 255.0f), static_cast<uint8_t>(m_gColor * 255.0f), static_cast<uint8_t>(m_bColor * 255.0f) });
}

void CollideableObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Rectangle);
}
