#pragma once

#include <Engine/Collision.h>

class Wall : public sf::Drawable//, public BoxCollideable
{
public:
	Wall(float xCenterPos, float yCenterPos, float width, float height);
	Wall(const Wall& other);
	~Wall();

	void Update(float deltaTime);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void onCollision(const BoxCollideable&) {}

private:
	sf::RectangleShape m_Rectangle;

	float m_rColor;
	float m_gColor;
	float m_bColor;

	BoxCollideable m_BoundingBox;
};

