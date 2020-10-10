#include "Text.hpp"

namespace ui
{
	Text::Text() : text()
	{
	}

	Text::Text(const sf::String& string, const sf::Font& font, unsigned int characterSize) :
		text(string, font, characterSize)
	{
	}

	Text::~Text()
	{
	}

	void Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		states.texture = NULL;

		target.draw(text, states);
	}
}
