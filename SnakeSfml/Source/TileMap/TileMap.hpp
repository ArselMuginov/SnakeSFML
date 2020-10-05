#pragma once
#include "TileType.hpp"
#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	TileMap(const sf::Texture& tileset, sf::Vector2u tileSize, unsigned int width, unsigned int height);
	~TileMap();
	
	void tile(const TileType* tiles);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::VertexArray m_vertices;
	const sf::Texture* m_tileset;
	sf::Vector2u m_tileSize;
	unsigned int m_width;
	unsigned int m_height;
};
