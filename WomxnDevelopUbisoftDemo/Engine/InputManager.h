#pragma once

#include <map>
#include <functional>

template<class T>
using InputCallback = void(T::*)();

class InputManager
{
public:
	static InputManager* GetInstance();

	// Binds a keyboard key to a function, needs to be on header file
	// otherwise compiler tries to resolve a "yet unknown" templated function  type
	template<class T>
	inline void BindKey(const sf::Keyboard::Key& key, T& instance, InputCallback<T> callback)
	{
		m_keyBindings[key] = std::bind(callback, &instance);
	}

	bool RemoveKey(const sf::Keyboard::Key&);

	void Update();

private:
	InputManager();
	static InputManager* _Instance;
	
	std::map <sf::Keyboard::Key, std::function<void(void)>> m_keyBindings;
};

