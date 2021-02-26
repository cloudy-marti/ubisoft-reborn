#pragma once

class Collectible : public sf::Drawable, public BoxCollideable
{
public:
	Collectible(const int, const std::string&);
	virtual ~Collectible() {}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:

private:
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;

	sf::Vector2f m_Position;
};

