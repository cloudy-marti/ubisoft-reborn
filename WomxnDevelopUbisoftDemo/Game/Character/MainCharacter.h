#pragma once

#include "Character.h"

class MainCharacter : public Character
{

public:	
	MainCharacter(const std::string&);
	void Update(float) override;

	inline bool IsCollidingWall() const { return m_isCollidingRigidBody; }
	inline bool IsCameraSafe() const { return m_CameraSafe && !m_isCollidingRigidBody; }

	void onCollision(const BoxCollideable&) override;
	void Die() override;

	bool m_HasDiedOnce = false;
	bool m_SteppedOnCheckPoint = false;

	inline bool HasSword() const { return m_HasSword; }
	void AttackWithSword();

	void TakeDamage(float) override;

private:
	void BindActionKeys();

	bool m_HasSword = false;

	bool m_CameraSafe;
	bool m_IsPlayingEndGame;

	bool m_IsTakingDamage = false;
	float m_DamageTime = 0.2f;

// Private member-functions that are binded to InputManager
private:
	inline void GoRight();
	inline void GoLeft();
	inline void GoDown();
	inline void GoUp();
};