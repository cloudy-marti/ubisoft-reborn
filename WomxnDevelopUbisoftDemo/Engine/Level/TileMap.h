#pragma once

#include <Game/Object/CollideableObject.h>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	bool load(const std::string& tileset, sf::Vector2f tileSize, /*const int**/const std::vector<std::string>& tiles, size_t width, size_t height);
	void addCollideableObject(float xCenterPos, float yCenterPos, float width, float height);
	void addTriggerableObject(sf::Vector2f center, float width, float height);

	inline const std::vector<CollideableObject*> getWalls() const { return m_Walls; }

private:
	int ProcessMapTileAndGetTileNumber(const std::vector<std::string>& tiles, size_t i, size_t j, size_t width, sf::Vector2f tileSize);
	void ProcessMapTile(int tileNumber, size_t i, size_t j, sf::Vector2f tileSize);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::VertexArray m_Vertices;
	sf::Texture m_Tileset;

	std::vector<CollideableObject*> m_Walls;

	enum class TileIndex
	{
		GRASS,
		FLOWERS,
		V_WOOD_FLOOR,
		H_WOOD_FLOOR,
		ROCK_FLOOR,
		WATER,
		TREE,
		BUSH
	};
};

