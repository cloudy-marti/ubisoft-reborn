#include "stdafx.h"

Character::Character(sf::Vector2f position, float max_speed, float hp, float max_hp, float cooldown, const std::string& filePath, BoxCollideable::Tag tag)
    : m_Position                { position }
    , m_MaxSpeed                { max_speed }
    , m_OldPosition             { position }
    , m_LastCheckPoint          { position }
    , m_isCollidingRigidBody    { false }
    , m_MaxHealthPoints         { max_hp }
    , m_HealthPoints            { hp }
    , m_CoolDown                { cooldown }
    , m_CurrentCoolDown         { cooldown }
    , m_OnCoolDown              { false }
{
    m_Texture.loadFromFile(filePath);

    const sf::Vector2f textureSize(static_cast<float>(m_Texture.getSize().x), static_cast<float>(m_Texture.getSize().y));

    m_Sprite.setTexture(m_Texture);
    m_Sprite.setOrigin(textureSize * .5f);
    m_Sprite.setPosition(m_Position);
    m_Sprite.setScale({ .5f, .5f });

    m_BoundingBox->setTag(tag);
    m_BoundingBox->SetBoundingBox(m_Position, textureSize * .5f);
}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Sprite);
    for (auto& object : m_InstanciatedObjects)
    {
        object->draw(target, states);
    }
}

void Character::CollidesRigidBody()
{
    m_isCollidingRigidBody = true;
}

void Character::TakeDamage(float hp)
{
    m_HealthPoints -= hp;
    if (m_HealthPoints <= 0)
    {
        Die();
    }
}

void Character::setPosition(sf::Vector2f position)
{
    m_Position = position;
    m_Sprite.setPosition(m_Position);
    m_BoundingBox->SetCenter(m_Position);
}
void Character::SetTexture(const std::string& path)
{
    m_Texture.loadFromFile(path);
    m_Sprite.setTexture(m_Texture);
}
