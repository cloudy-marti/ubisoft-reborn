#pragma once

#include <string>

class Character : public sf::Drawable
{
public:
	virtual ~Character() {}

	virtual void Update(float deltaTime) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void onCollision(const BoxCollideable&) = 0;
	virtual void CollidesWall();

	sf::Vector2f GetCenter() const { return m_BoundingBox.GetCenter(); }

protected:
	Character(sf::Vector2f position, float factor, int hp, const std::string& filePath, BoxCollideable::Tag tag);

	sf::Texture m_Texture;
	sf::Sprite m_Sprite;

	sf::Vector2f m_Position;
	sf::Vector2f m_Velocity;

	bool m_isCollidingWall;

	int m_HealthPoints;

	BoxCollideable m_BoundingBox;
};