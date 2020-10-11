#pragma once
#include "UIElement.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace ui
{
	class Text : public UIElement
	{
	public:
		Text();
		Text(const sf::String& string, const sf::Font& font, unsigned int characterSize = 30);

		sf::Text text;

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}
