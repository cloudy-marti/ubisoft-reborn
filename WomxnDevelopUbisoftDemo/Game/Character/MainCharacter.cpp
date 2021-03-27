#include <stdafx.h>

using namespace sf;

// Joystick helpers
namespace
{
    bool GetFirstJoystickIndex(unsigned int& index)
    {
        index = 0;
        while (index < Joystick::Count)
        {
            if (Joystick::isConnected(index) && Joystick::hasAxis(index, Joystick::Axis::X) && Joystick::hasAxis(index, Joystick::Axis::Y))
                return true;

            index++;
        }

        return false;
    }

    float GetScaledAxis(unsigned int index, sf::Joystick::Axis axis, float deadZone, float scale)
    {
        float value = (Joystick::getAxisPosition(index, axis) / 100.0f) * scale;
        if (value >= -deadZone && value <= deadZone)
            return 0.0f;

        return value;
    }
}


MainCharacter::MainCharacter(const std::string& filePath)
    : Character{ { 250.f, 250.f }, .5f, 3.f, 15.f, 0.f, filePath, BoxCollideable::Tag::PLAYER }
    , m_IsPlayingEndGame  { false }
    , m_IsUsingJoystick   { false }
    , m_JoystickIndex     { 0 }
    , m_IsOnSlipperyFloor { false }
    , m_WasButtonPressed  { false }
    , m_CameraSafe        { false }
{
    m_IsUsingJoystick = GetFirstJoystickIndex(m_JoystickIndex);

    InputManager* inputManager = InputManager::GetInstance();
    inputManager->BindKey(Keyboard::Right, *this, &MainCharacter::GoRight);
    inputManager->BindKey(Keyboard::Left, *this, &MainCharacter::GoLeft);
    inputManager->BindKey(Keyboard::Up, *this, &MainCharacter::GoUp);
    inputManager->BindKey(Keyboard::Down, *this, &MainCharacter::GoDown);

    m_BoundingBox.BindOnCollisionFunc(*this, &MainCharacter::onCollision);
}


void MainCharacter::Update(float deltaTime)
{
    m_CameraSafe = false;

    if (m_IsPlayingEndGame)
    {
        return;
    }

    if (m_IsUsingJoystick)
    {
        m_Velocity.x = GetScaledAxis(m_JoystickIndex, Joystick::Axis::X, DEAD_ZONE, SPEED_MAX);
        m_Velocity.y = GetScaledAxis(m_JoystickIndex, Joystick::Axis::Y, DEAD_ZONE, SPEED_MAX);

        if (Joystick::isButtonPressed(m_JoystickIndex, 0))
        {
            if (!m_WasButtonPressed)
            {
                m_Sprite.setScale(0.8f, 0.8f);
                m_WasButtonPressed = true;
            }
        }
        else
        {
            if (m_WasButtonPressed)
            {
                m_Sprite.setScale(1.0f, 1.0f);
                m_WasButtonPressed = false;
            }
        }
    }

    m_Velocity.x *= SLOWDOWN_RATE;
    m_Velocity.y *= SLOWDOWN_RATE;

    if (m_isCollidingRigidBody)
    {
        m_Position = m_OldPosition;
        m_isCollidingRigidBody = false;
    }
    else
    {
        m_OldPosition = m_Position;
        m_Position += m_Velocity * deltaTime;
        m_CameraSafe = true;
    }

    m_Sprite.setPosition(m_Position);
    m_BoundingBox.SetCenter(m_Position);
    m_Velocity = { 0.f, 0.f };
}

void MainCharacter::StartEndGame()
{
    m_IsPlayingEndGame = true;
}

void MainCharacter::onCollision(const BoxCollideable& other)
{
    BoxCollideable::Tag tag = other.getTag();

    switch (tag)
    {
    case BoxCollideable::Tag::COMPANION:
    {
        CollidesRigidBody();
        break;
    }
    case BoxCollideable::Tag::ENEMY:
        break;
    case BoxCollideable::Tag::WALL:
    {
        CollidesRigidBody();
        break;
    }
    case BoxCollideable::Tag::PLAYER:
    default:
        break;
    }
}

// Use SPEED_MAX only if you want "just walking"
// Uncomment SlowDown rate on Update function if you need a smoother walking speed
inline void MainCharacter::GoRight()
{
    if (!m_IsOnSlipperyFloor)
    {
        m_Velocity.x = SPEED_MAX;
    }
    else
    {
        m_Velocity.x = fmin(m_Velocity.x + SPEED_INC, SPEED_MAX);
    }
}

inline void MainCharacter::GoLeft()
{
    if (!m_IsOnSlipperyFloor)
    {
        m_Velocity.x = -SPEED_MAX;
    }
    else
    {
        m_Velocity.x = fmax(m_Velocity.x - SPEED_INC, -SPEED_MAX);
    }
}

inline void MainCharacter::GoDown()
{
    if (!m_IsOnSlipperyFloor)
    {
        m_Velocity.y = SPEED_MAX;
    }
    else
    {
        m_Velocity.y = fmin(m_Velocity.y + SPEED_INC, SPEED_MAX);
    }
}

inline void MainCharacter::GoUp()
{
    if (!m_IsOnSlipperyFloor)
    {
        m_Velocity.y = -SPEED_MAX;
    }
    else
    {
        m_Velocity.y = fmax(m_Velocity.y - SPEED_INC, -SPEED_MAX);
    }
}