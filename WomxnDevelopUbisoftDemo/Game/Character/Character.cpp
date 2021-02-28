#include "stdafx.h"

Character::Character(sf::Vector2f position, float factor, int hp, const std::string& filePath, BoxCollideable::Tag tag)
    : m_Position        { position }
    , m_isCollidingWall { false }
    , m_HealthPoints    { hp }
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

void Character::CollidesWall()
{
    m_isCollidingWall = true;
}
