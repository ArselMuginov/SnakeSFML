#include "Label.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

Label::Label() : text{}
{
}

Label::Label(const sf::String& string, const sf::Font& font, unsigned int characterSize) :
	text{string, font, characterSize}
{
}

sf::FloatRect Label::getLocalBounds() const
{
	const sf::FloatRect innerBounds = text.getGlobalBounds();
	return {
		0,
		0,
		innerBounds.left + innerBounds.width,
		innerBounds.top + innerBounds.height
	};
}

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = nullptr;

	target.draw(text, states);
}
