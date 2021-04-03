#include "stdafx.h"

Character::Character(sf::Vector2f position, float factor, float hp, float max_hp, float cooldown, const std::string& filePath, BoxCollideable::Tag tag)
    : m_Position                { position }
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
    m_Sprite.setOrigin(textureSize * 0.5f);
    m_Sprite.setPosition(m_Position);
    m_Sprite.setScale({ factor, factor });

    m_BoundingBox.setTag(tag);
    m_BoundingBox.SetBoundingBox(m_Position, textureSize * factor);
}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Sprite);
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
