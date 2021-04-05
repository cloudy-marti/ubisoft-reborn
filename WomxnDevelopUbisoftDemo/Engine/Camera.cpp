#include "stdafx.h"

Camera::Camera(const sf::View& defaultView)
	: m_View { defaultView }
{
	m_View.zoom(0.6f);
	InputManager* inputManager = InputManager::GetInstance();
	inputManager->BindKey(sf::Keyboard::Add, sf::Keyboard::Add, sf::Keyboard::Add, *this, &Camera::ZoomIn);
	inputManager->BindKey(sf::Keyboard::Subtract, sf::Keyboard::Subtract, sf::Keyboard::Subtract, *this, &Camera::ZoomOut);
}