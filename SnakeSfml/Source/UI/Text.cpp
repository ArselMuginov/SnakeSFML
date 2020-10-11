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

	void Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		states.texture = nullptr;

		target.draw(text, states);
	}
}
