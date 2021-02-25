#pragma once

#include "Character.h"

class MainCharacter : public Character //public sf::Drawable, public BoxCollideable
{
public:	
	MainCharacter();

	void Update(float deltaTime) override;
	//void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	//void CollidesWall();

	void StartEndGame();

private:
	//sf::Texture m_Texture;
	//sf::Sprite m_Sprite;

	bool m_IsUsingJoystick;
	unsigned int m_JoystickIndex;
	bool m_WasButtonPressed;

	//sf::Vector2f m_Position; 
	//sf::Vector2f m_Velocity;
	//bool m_isCollidingWall;

	bool m_IsPlayingEndGame;
};