#include "stdafx.h"
#include "Character.h"

Character::Character()
    : m_Position(250.0f, 250.0f)
    , m_isCollidingWall(false)
{
    m_Texture.loadFromFile(".\\Assets\\red_ball.bmp");

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
