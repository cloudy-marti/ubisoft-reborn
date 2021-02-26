#include "stdafx.h"
#include "InputManager.h"

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

void InputManager::BindKey(sf::Keyboard::Key key, InputCallback callback)
{
    m_keyBindings[key] = callback;
}

bool InputManager::RemoveKey(sf::Keyboard::Key key)
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
    for (auto const& [key, val] : m_keyBindings)
    {
        if (!sf::Keyboard::isKeyPressed(key))
        {
            continue;
        }
        val();
    }
}
