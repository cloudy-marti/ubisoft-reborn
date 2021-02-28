#include <stdafx.h>


Door::Door(float xCenterPos, float yCenterPos, float width, float height)
	: m_IsPlayingEndGame{ false }
	, m_rColor{ 0.0f }
	, m_gColor{ 1.0f }
	, m_bColor{ 1.0f }
	, m_BoundingBox { BoxCollideable::Tag::CHECKPOINT }
{
	const auto center = sf::Vector2f(xCenterPos, yCenterPos);
	const auto size = sf::Vector2f(width, height);

	m_BoundingBox.SetBoundingBox(center, size);
	m_BoundingBox.BindOnCollisionFunc(*this, &Door::onCollision);

	m_Rectangle.setSize(size);
	m_Rectangle.setOrigin(size * 0.5f);
	m_Rectangle.setPosition(center);

	m_Rectangle.setFillColor(sf::Color(0, 0, 0, 0));
	m_Rectangle.setOutlineThickness(1);
	m_Rectangle.setOutlineColor(sf::Color{ static_cast<uint8_t>(m_rColor * 255.0f), static_cast<uint8_t>(m_gColor * 255.0f), static_cast<uint8_t>(m_bColor * 255.0f) });
}

Door::~Door()
{
}

void Door::Update(float deltaTime)
{
	if (!m_IsPlayingEndGame)
	{
		return;
	}

	float colorDelta = 0.2f * deltaTime /1000.0f;

	m_rColor = fmodf(m_rColor+colorDelta, 1.f);
	m_gColor = fmodf(m_gColor+colorDelta, 1.f);
	m_bColor = fmodf(m_bColor+colorDelta, 1.f);
	m_Rectangle.setOutlineColor(sf::Color{ static_cast<uint8_t>(m_rColor * 255.0f), static_cast<uint8_t>(m_gColor * 255.0f), static_cast<uint8_t>(m_bColor * 255.0f) });
}

void Door::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Rectangle);
}

void Door::StartEndGame()
{
	m_IsPlayingEndGame = true;

	m_rColor = 0.25f;
	m_gColor = 0.5f;
	m_bColor = 0.75f;
}

bool Door::IsEndGame() const
{
	return m_IsPlayingEndGame;
}

void Door::onCollision(const BoxCollideable& other)
{
	BoxCollideable::Tag tag = other.getTag();

	switch (tag)
	{
	case BoxCollideable::Tag::PLAYER:
	{
		if (m_BoundingBox.Contains(other))
		{
			StartEndGame();
			/*
			m_EndgameSound.play();

			m_MainCharacter.StartEndGame();
			m_Door.StartEndGame();
			m_IsFinished = true;
			*/
		}
		break;
	}
	case BoxCollideable::Tag::COMPANION:
	case BoxCollideable::Tag::ENEMY:
	case BoxCollideable::Tag::CHECKPOINT:
	case BoxCollideable::Tag::WALL:
	default:
		break;
	}
}
