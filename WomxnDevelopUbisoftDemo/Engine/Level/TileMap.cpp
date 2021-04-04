#include "stdafx.h"
#include <iostream>

bool TileMap::load(const std::string& tileset, sf::Vector2f tileSize, const std::vector<std::string>& tiles, size_t width, size_t height)
{
	if (!m_Tileset.loadFromFile(tileset))
	{
        std::cerr << "Tileset file not found" << std::endl;
		return false;
	}

	m_Vertices.setPrimitiveType(sf::Quads);
	m_Vertices.resize(width * height * 4);

	for (size_t i = 0; i < width; ++i)
	{
		for (size_t j = 0; j < height; ++j)
		{
            // get the current tile number
            int tileNumber = ProcessMapTileAndGetTileNumber(tiles, i, j, width, tileSize);

            // find its position in the tileset texture
            int tu = tileNumber % (m_Tileset.getSize().x / static_cast<int>(tileSize.x));
            int tv = tileNumber / (m_Tileset.getSize().x / static_cast<int>(tileSize.x));

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_Vertices[(i + (j * width)) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}
	}

    return true;
}

int TileMap::ProcessMapTileAndGetTileNumber(const std::vector<std::string>& tiles, size_t i, size_t j, size_t width, sf::Vector2f tileSize)
{
    int tileNumber;
    std::string tmp = tiles[i + j * width];

    tileNumber = std::stoi(tmp);

    if (tileNumber > 1 && std::isdigit(tmp.back()))
    {
        addCollideableObject(i * (tileSize.x + 1), j * (tileSize.y + 1), tileSize.x, tileSize.y);
    }
    return tileNumber;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &m_Tileset;
	target.draw(m_Vertices, states);
}

void TileMap::addCollideableObject(float xCenterPos, float yCenterPos, float width, float height)
{
    CollideableObject* w = new CollideableObject{ xCenterPos, yCenterPos, width, height };
    m_Walls.push_back(w);
}

void TileMap::addTriggerableObject(sf::Vector2f center, float width, float height)
{
    // TODO
}
