#pragma once

class Collectible : public sf::Drawable
{
public:
	Collectible(sf::Vector2f, sf::Vector2f, const std::string&, float, BoxCollideable::Tag);

	Collectible(const Collectible&) = delete;
	Collectible& operator=(const Collectible&) = delete;
	~Collectible()
	{
		m_BoundingBox->setTag(BoxCollideable::Tag::OUT_OF_SIM);
	}

	void Update(float);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	inline bool HasToDisappear() const { return m_Disappeared; }

	void onCollision(const BoxCollideable&) {}

protected:

private:
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;

	sf::Vector2f m_Position;
	sf::Vector2f m_Velocity;

	BoxCollideable* m_BoundingBox = new BoxCollideable;

	float m_TimeToLive;

	bool m_Disappeared = false;
};