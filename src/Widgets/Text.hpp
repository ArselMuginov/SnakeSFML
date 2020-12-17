#pragma once
#include "Widgets/Widget.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Text : public Widget
{
public:
	Text();
	Text(const sf::String& string, const sf::Font& font, unsigned int characterSize = 30);

	template <class... Ts>
	static std::unique_ptr<Text> create(Ts&&... args);

	virtual sf::FloatRect getLocalBounds() const;

	sf::Text text;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
