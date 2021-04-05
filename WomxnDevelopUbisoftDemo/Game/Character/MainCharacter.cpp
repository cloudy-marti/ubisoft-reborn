#include <stdafx.h>

using namespace sf;

MainCharacter::MainCharacter(const std::string& filePath)
    : Character{ { 400.f, 400.f }, 150.f, 3.f, 7.f, 0.f, filePath, BoxCollideable::Tag::PLAYER }
    , m_IsPlayingEndGame    { false }
    , m_CameraSafe          { false }
{
    BindDirectionKeys();

    m_BoundingBox.BindOnCollisionFunc(*this, &MainCharacter::onCollision);
}

/* To be called only on constructor */
void MainCharacter::BindDirectionKeys()
{
    InputManager* inputManager = InputManager::GetInstance();

    inputManager->BindKey(Keyboard::Up,    Keyboard::W, Keyboard::Z, *this, &MainCharacter::GoUp);
    inputManager->BindKey(Keyboard::Left,  Keyboard::A, Keyboard::Q, *this, &MainCharacter::GoLeft);
    inputManager->BindKey(Keyboard::Down,  Keyboard::S, Keyboard::S, *this, &MainCharacter::GoDown);
    inputManager->BindKey(Keyboard::Right, Keyboard::D, Keyboard::D, *this, &MainCharacter::GoRight);
}

void MainCharacter::Update(float deltaTime)
{
    m_CameraSafe = false;

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

void MainCharacter::onCollision(const BoxCollideable& other)
{
    BoxCollideable::Tag tag = other.getTag();

    switch (tag)
    {
    case BoxCollideable::Tag::CHECKPOINT:
    {
        m_SteppedOnCheckPoint = true;
        break;
    }
    case BoxCollideable::Tag::WALL:
    {
        CollidesRigidBody();
        break;
    }
    case BoxCollideable::Tag::COMPANION:
    case BoxCollideable::Tag::ENEMY:
    default:
        break;
    }
}

void MainCharacter::Die()
{
    if (m_HasDiedOnce)
    {
        m_Position = m_LastCheckPoint;
    }
    else
    {
        m_HasDiedOnce = true;
        m_HasSword = true;
    }
    m_HealthPoints = m_MaxHealthPoints;
}

inline void MainCharacter::GoRight()
{
    m_Velocity.x = m_MaxSpeed;
}

inline void MainCharacter::GoLeft()
{
    m_Velocity.x = -m_MaxSpeed;
}

inline void MainCharacter::GoDown()
{
    m_Velocity.y = m_MaxSpeed;
}

inline void MainCharacter::GoUp()
{
    m_Velocity.y = -m_MaxSpeed;
}