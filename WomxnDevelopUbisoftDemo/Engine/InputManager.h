#pragma once

#include <map>
#include <functional>

template<class T>
using InputCallback = void(T::*)();

class InputManager
{
public:
	enum class Layout
	{
		ARROWS,
		QWERTY,
		AZERTY,
		L_SIZE
	};

public:
	static InputManager* GetInstance();

	// Binds a keyboard key to a function, needs to be on header file
	// otherwise compiler tries to resolve a "yet unknown" templated function  type
	template<class T>
	void BindKey(const sf::Keyboard::Key& key, const sf::Keyboard::Key& qwertyKey, const sf::Keyboard::Key& azertyKey, T& instance, InputCallback<T> callback)
	{
		m_keyBindings[key]		  = std::bind(callback, &instance);
		m_qKeyBindings[qwertyKey] = std::bind(callback, &instance);
		m_aKeyBindings[azertyKey] = std::bind(callback, &instance);
	}
	bool RemoveKey(const sf::Keyboard::Key&);

	void Update();

	void ToggleKeyboardLayout();
	std::string GetKeyboardLayout() const;

private:
	InputManager();
	static InputManager* _Instance;

	Layout m_KeyboardLayout = Layout::ARROWS;
	
	std::map <sf::Keyboard::Key, std::function<void(void)>> m_keyBindings;
	std::map <sf::Keyboard::Key, std::function<void(void)>> m_qKeyBindings;
	std::map <sf::Keyboard::Key, std::function<void(void)>> m_aKeyBindings;

	std::map <sf::Keyboard::Key, std::function<void(void)>>& m_CurrentKeyBindings = m_keyBindings;
};

