#pragma once

#include <string>

class Character : public sf::Drawable, public BoxCollideable
{
public:
	virtual ~Character() {}

	virtual void Update(float deltaTime) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void CollidesWall();

protected:
	Character(sf::Vector2f, int, const std::string&);

	sf::Texture m_Texture;
	sf::Sprite m_Sprite;

	sf::Vector2f m_Position;
	sf::Vector2f m_Velocity;

	bool m_isCollidingWall;

	int m_HealthPoints;

private:
};