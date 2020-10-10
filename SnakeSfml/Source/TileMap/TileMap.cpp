#include "TileMap.hpp"

TileMap::TileMap(const sf::Texture& tileset, sf::Vector2u tileSize, unsigned int width, unsigned int height) :
	m_vertices(sf::Quads, width* height * 4),
	m_tileset(&tileset),
	m_tileSize(tileSize),
	m_width(width),
	m_height(height)
{
}

TileMap::~TileMap()
{
}

void TileMap::tile(const TileType* tiles)
{
	// Code from https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php#example-tile-map

	// populate the vertex array, with one quad per tile
	for (unsigned int i = 0; i < m_width; ++i)
	{
		for (unsigned int j = 0; j < m_height; ++j)
		{
			// get the current tile number
			int tileNumber = static_cast<int>(tiles[i + j * m_width]);

			// find its position in the tileset texture
			int tu = tileNumber % (m_tileset->getSize().x / m_tileSize.x);
			int tv = tileNumber / (m_tileset->getSize().x / m_tileSize.x);

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &m_vertices[(i + j * m_width) * 4];

			// define its 4 corners
			quad[0].position = sf::Vector2f(i * m_tileSize.x, j * m_tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * m_tileSize.x, j * m_tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * m_tileSize.x, (j + 1) * m_tileSize.y);
			quad[3].position = sf::Vector2f(i * m_tileSize.x, (j + 1) * m_tileSize.y);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * m_tileSize.x, tv * m_tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * m_tileSize.x, tv * m_tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * m_tileSize.x, (tv + 1) * m_tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * m_tileSize.x, (tv + 1) * m_tileSize.y);
		}
	}
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = m_tileset;

	target.draw(m_vertices, states);
}
