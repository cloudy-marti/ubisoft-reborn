#pragma once

#include "Character.h"

class MainCharacter : public Character
{
public:	
	MainCharacter(const std::string&);
	void Update(float) override;
	void StartEndGame();

private:
	bool m_IsUsingJoystick;
	unsigned int m_JoystickIndex;
	bool m_WasButtonPressed;

	bool m_IsOnSlipperyFloor;

	bool m_IsPlayingEndGame;

// Private constants only used within this class
private:
	const float SPEED_MAX = 150.0f;
	const float SPEED_INC = 10.0f;
	const float DEAD_ZONE = 5.0f;
	const float SLOWDOWN_RATE = 0.95f;

// Private member-functions that are called by InputManager
private:
	inline void GoRight();
	inline void GoLeft();
	inline void GoDown();
	inline void GoUp();
};