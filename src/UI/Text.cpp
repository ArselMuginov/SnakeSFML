#include "UI/Text.hpp"

namespace ui
{
	Text::Text() : text()
	{
	}

	Text::Text(const sf::String& string, const sf::Font& font, unsigned int characterSize) :
		text(string, font, characterSize)
	{
	}

	template <class... Ts>
	std::unique_ptr<Text> Text::create(Ts&&... args)
	{
		return std::make_unique<Text>(std::forward<Ts>(args)...);
	}

	sf::FloatRect Text::getLocalBounds() const
	{
		return text.getLocalBounds();
	}

	void Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		states.texture = nullptr;

		target.draw(text, states);
	}
}
