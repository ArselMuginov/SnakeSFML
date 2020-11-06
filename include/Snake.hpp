#pragma once
#include <SFML/System/Vector2.hpp>

struct Snake
{
public:
	Snake(unsigned int headPosition, sf::Vector2i headDirection, unsigned int length);

	unsigned int headPosition;
	sf::Vector2i headDirection;
	unsigned int length;
};
