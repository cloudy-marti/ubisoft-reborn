#pragma once

#include <Engine/Physics/BoxCollideable.h>

class CollideableObject : public sf::Drawable
{
public:
	CollideableObject(float xCenterPos, float yCenterPos, float width, float height);
	CollideableObject(const CollideableObject& other) = delete;
	~CollideableObject();

	void Update(float deltaTime);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void onCollision(const BoxCollideable&) {}

private:
	sf::RectangleShape m_Rectangle;

	float m_rColor;
	float m_gColor;
	float m_bColor;

	BoxCollideable* m_BoundingBox = new BoxCollideable;
};

