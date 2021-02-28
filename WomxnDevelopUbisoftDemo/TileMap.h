#pragma once

#include <Game/Wall.h>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	bool load(const std::string& tileset, sf::Vector2f tileSize, const int* tiles, size_t width, size_t height);
	void addWall(float xCenterPos, float yCenterPos, float width, float height);

	inline const std::vector<Wall*> getWalls() const { return m_Walls; }

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::VertexArray m_Vertices;
	sf::Texture m_Tileset;

	std::vector<Wall*> m_Walls;
};

