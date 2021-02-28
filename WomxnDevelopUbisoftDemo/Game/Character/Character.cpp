#include "stdafx.h"

Character::Character(sf::Vector2f position, int hp, const std::string& filePath)
    : m_Position        { position }
    , m_isCollidingWall { false }
    , m_HealthPoints    { hp }
{
    m_Texture.loadFromFile(filePath);

    const sf::Vector2f size(static_cast<float>(m_Texture.getSize().x), static_cast<float>(m_Texture.getSize().y));

    m_Sprite.setTexture(m_Texture);
    m_Sprite.setOrigin(size * 0.5f);
    m_Sprite.setPosition(m_Position);

    SetBoundingBox(m_Position, size);
}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Sprite);
}

void Character::CollidesWall()
{
    m_isCollidingWall = true;
}
