#pragma once

#include <string>

class Character : public sf::Drawable
{
public:
	virtual ~Character() {}

	virtual void Update(float deltaTime) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void onCollision(const BoxCollideable&) = 0;
	virtual void CollidesRigidBody();

	sf::Vector2f GetCenter() const { return m_BoundingBox.GetCenter(); }

	const float GetHP() const { return m_HealthPoints; }
	void Heal(float hp) { m_HealthPoints = m_HealthPoints + hp <= m_MaxHealthPoints ? m_HealthPoints + hp : m_MaxHealthPoints; }

protected:
	Character(sf::Vector2f position, float factor, float hp, float max_hp, float cooldown, const std::string& filePath, BoxCollideable::Tag tag);

	// Private constants
	const float SPEED_MAX = 150.0f;
	const float SPEED_INC = 10.0f;
	const float DEAD_ZONE = 5.0f;
	const float SLOWDOWN_RATE = 0.9f;

	sf::Texture m_Texture;
	sf::Sprite m_Sprite;

	sf::Vector2f m_Position;
	sf::Vector2f m_OldPosition;
	sf::Vector2f m_Velocity;

	bool m_isCollidingRigidBody;

	float m_MaxHealthPoints;
	float m_HealthPoints;
	float m_CoolDown;

	BoxCollideable m_BoundingBox;
};