#pragma once

#include <Game/CollideableObject.h>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	bool load(const std::string& tileset, sf::Vector2f tileSize, const int* tiles, size_t width, size_t height);
	void addCollideableObject(float xCenterPos, float yCenterPos, float width, float height);
	void addTriggerableObject(sf::Vector2f center, float width, float height);

	inline const std::vector<CollideableObject*> getWalls() const { return m_Walls; }

private:
	void ProcessMapTile(int tileNumber, size_t i, size_t j, sf::Vector2f tileSize);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::VertexArray m_Vertices;
	sf::Texture m_Tileset;

	std::vector<CollideableObject*> m_Walls;
};

