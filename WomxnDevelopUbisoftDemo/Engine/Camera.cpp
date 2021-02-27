#include "stdafx.h"
#include "Camera.h"

Camera::Camera(const sf::View& defaultView)
	: m_View { defaultView }
{
	InputManager* inputManager = InputManager::GetInstance();
	inputManager->BindKey(sf::Keyboard::Add, *this, &Camera::ZoomIn);
	inputManager->BindKey(sf::Keyboard::Subtract, *this, &Camera::ZoomOut);
}