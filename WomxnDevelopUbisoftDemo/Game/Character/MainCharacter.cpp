#include <stdafx.h>

using namespace sf;

MainCharacter::MainCharacter(const std::string& filePath)
    : Character{ { 400.f, 400.f }, 135.f, 3.f, 7.f, 1.5f, filePath, BoxCollideable::Tag::PLAYER }
    , m_IsPlayingEndGame    { false }
    , m_CameraSafe          { false }
{
    BindActionKeys();
    m_BoundingBox->BindOnCollisionFunc(*this, &MainCharacter::onCollision);
}

void MainCharacter::AttackWithSword()
{
    if (m_HasSword && !m_OnCoolDown)
    {
        sf::Vector2f position = { m_Position.x + ((m_LastVelocity.x / m_MaxSpeed) * 45.f), m_Position.y };
        m_InstanciatedObjects.emplace_back(new Collectible{ position, {0.f, 0.f}, ".\\Assets\\object\\slash.png", 0.3f, BoxCollideable::Tag::DAMAGING_OBJECT });
        m_OnCoolDown = true;
    }
}

void MainCharacter::TakeDamage(float hp)
{
    Character::TakeDamage(hp);
    m_IsTakingDamage = true;
    m_Sprite.setColor(sf::Color::Red);
}

/* To be called only on constructor */
void MainCharacter::BindActionKeys()
{
    InputManager* inputManager = InputManager::GetInstance();

    inputManager->BindKey(Keyboard::Up,    Keyboard::W, Keyboard::Z, *this, &MainCharacter::GoUp);
    inputManager->BindKey(Keyboard::Left,  Keyboard::A, Keyboard::Q, *this, &MainCharacter::GoLeft);
    inputManager->BindKey(Keyboard::Down,  Keyboard::S, Keyboard::S, *this, &MainCharacter::GoDown);
    inputManager->BindKey(Keyboard::Right, Keyboard::D, Keyboard::D, *this, &MainCharacter::GoRight);
    inputManager->BindKey(sf::Keyboard::Space, sf::Keyboard::Space, sf::Keyboard::Space, *this, &MainCharacter::AttackWithSword);
}

void MainCharacter::Update(float deltaTime)
{
    m_CameraSafe = false;

    m_Velocity.x *= SLOWDOWN_RATE;
    m_Velocity.y *= SLOWDOWN_RATE;

    for (auto& object : m_InstanciatedObjects)
    {
        object->Update(deltaTime);
    }

    if (m_OnCoolDown)
    {
        m_CurrentCoolDown -= deltaTime;
        if (m_CurrentCoolDown <= 0)
        {
            m_CurrentCoolDown = m_CoolDown;
            m_OnCoolDown = false;
        }
    }

    if (m_IsTakingDamage)
    {
        m_DamageTime -= deltaTime;
        if (m_DamageTime <= 0.f)
        {
            m_Sprite.setColor(sf::Color::White);
            m_IsTakingDamage = false;
            m_DamageTime = 0.2f;
        }
    }

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
    m_BoundingBox->SetCenter(m_Position);
    if (m_Velocity.x != 0.f)
    {
        m_LastVelocity = m_Velocity;
    }
    m_Velocity = { 0.f, 0.f };

    m_InstanciatedObjects.erase(std::remove_if(m_InstanciatedObjects.begin(), m_InstanciatedObjects.end(),
        [](std::unique_ptr<Collectible>& object) { return object->HasToDisappear(); }), m_InstanciatedObjects.end());
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