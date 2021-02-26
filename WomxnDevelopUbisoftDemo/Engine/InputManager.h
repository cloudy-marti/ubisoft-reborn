#pragma once

#include <map>

using InputCallback = void(*)(void);

class InputManager
{
public:
	static InputManager* GetInstance();

	void BindKey(sf::Keyboard::Key, InputCallback);
	bool RemoveKey(sf::Keyboard::Key);

	void Update();

private:
	InputManager();
	static InputManager* _Instance;
	
	std::map < sf::Keyboard::Key, InputCallback > m_keyBindings;
};

