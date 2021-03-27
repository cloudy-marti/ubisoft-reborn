#pragma once

#include "Character.h"

class MainCharacter : public Character
{
public:	
	MainCharacter(const std::string&);
	void Update(float) override;
	void StartEndGame();

	inline bool IsCollidingWall() const { return m_isCollidingRigidBody; }
	inline bool IsCameraSafe() const { return m_CameraSafe; }

	void onCollision(const BoxCollideable&) override;

private:
	bool m_IsUsingJoystick;
	unsigned int m_JoystickIndex;
	bool m_WasButtonPressed;

	bool m_IsOnSlipperyFloor;

	bool m_CameraSafe;

	bool m_IsPlayingEndGame;

private:

// Private member-functions that are called by InputManager
private:
	inline void GoRight();
	inline void GoLeft();
	inline void GoDown();
	inline void GoUp();
};