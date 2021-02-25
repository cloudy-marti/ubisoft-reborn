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

	bool m_IsPlayingEndGame;
};