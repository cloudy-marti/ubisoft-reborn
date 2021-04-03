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

	inline sf::Vector2f GetCenter() const { return m_BoundingBox.GetCenter(); }

	inline const float GetHP() const { return m_HealthPoints; }
	inline void Heal(float hp) { m_HealthPoints = m_HealthPoints + hp <= m_MaxHealthPoints ? m_HealthPoints + hp : m_MaxHealthPoints; }
	virtual void TakeDamage(float hp);
	virtual void Die() = 0;

	/* Debug: To be deleted */
	inline std::string GetCoolDown()
	{
		return "cooldown : " + std::to_string(m_CoolDown) + "\ncurrent : " + std::to_string(m_CurrentCoolDown);
	}
	inline bool IsOnCoolDown() const { return m_OnCoolDown; }

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

	sf::Vector2f m_LastCheckPoint;

	bool m_isCollidingRigidBody;

	const float m_MaxHealthPoints;
	float m_HealthPoints;

	const float m_CoolDown;
	float m_CurrentCoolDown;
	bool  m_OnCoolDown;

	BoxCollideable m_BoundingBox;
};