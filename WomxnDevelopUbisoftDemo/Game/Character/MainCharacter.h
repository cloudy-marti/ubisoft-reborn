#pragma once

#include "Character.h"

class MainCharacter : public Character
{
public:	
	MainCharacter(const std::string&);
	void Update(float) override;
	void StartEndGame();

	inline bool IsCollidingWall() const { return m_isCollidingWall; }
	inline bool IsCameraSafe() const { return m_CameraSafe; }

	void onCollision(const BoxCollideable&) override;

private:
	bool m_IsUsingJoystick;
	unsigned int m_JoystickIndex;
	bool m_WasButtonPressed;

	bool m_IsOnSlipperyFloor;

	bool m_CameraSafe;

	bool m_IsPlayingEndGame;

// Private constants only used within this class
private:
	const float SPEED_MAX = 150.0f;
	const float SPEED_INC = 10.0f;
	const float DEAD_ZONE = 5.0f;
	const float SLOWDOWN_RATE = 0.9f;

// Private member-functions that are called by InputManager
private:
	inline void GoRight();
	inline void GoLeft();
	inline void GoDown();
	inline void GoUp();
};