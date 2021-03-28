#include "stdafx.h"

InputManager* InputManager::_Instance = nullptr;

InputManager::InputManager()
{
}

InputManager* InputManager::GetInstance()
{
    if (_Instance == nullptr)
    {
        _Instance = new InputManager();
    }
    return _Instance;
}


bool InputManager::RemoveKey(const sf::Keyboard::Key& key)
{
    if (m_keyBindings.find(key) != m_keyBindings.end())
    {
        m_keyBindings.erase(key);
        return true;
    }
    return false;
}

void InputManager::Update()
{    
    for (auto const& [key, val] : m_CurrentKeyBindings)
    {
        if (!sf::Keyboard::isKeyPressed(key))
        {
            continue;
        }
        val();
    }
}

void InputManager::ToggleKeyboardLayout()
{
	m_KeyboardLayout = static_cast<Layout>((static_cast<int>(m_KeyboardLayout) + 1) % static_cast<int>(Layout::L_SIZE));
	switch (m_KeyboardLayout)
	{
		case InputManager::Layout::QWERTY:
		{
			m_CurrentKeyBindings = m_qKeyBindings;
			break;
		}
		case InputManager::Layout::AZERTY:
		{
			m_CurrentKeyBindings = m_aKeyBindings;
			break;
		}
		default:
		{
			m_CurrentKeyBindings = m_keyBindings;
			break;
		}
	}
};