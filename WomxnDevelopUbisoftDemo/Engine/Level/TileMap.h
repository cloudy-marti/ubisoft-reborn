#pragma once

#include <Game/Object/CollideableObject.h>

class MainCharacter;
class Companion;
class Foe;

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	bool load(const std::string& tileset, sf::Vector2f tileSize, const std::vector<std::string>& tiles, size_t width, size_t height
		, MainCharacter& player, Companion& companion, std::vector<Foe*>& enemies);
	void addCollideableObject(float xCenterPos, float yCenterPos, float width, float height);
	void addTriggerableObject(sf::Vector2f center, float width, float height);

	inline const std::vector<CollideableObject*> getWalls() const { return m_Walls; }

private:
	int ProcessMapTileAndGetTileNumber(const std::vector<std::string>& tiles, size_t i, size_t j, size_t width, sf::Vector2f tileSize
		, MainCharacter& player, Companion& companion, std::vector<Foe*>& enemies);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::VertexArray m_Vertices;
	sf::Texture m_Tileset;

	std::vector<CollideableObject*> m_Walls;
};

