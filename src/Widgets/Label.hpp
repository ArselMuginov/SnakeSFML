#pragma once
#include "Widgets/Widget.hpp"
#include <SFML/Graphics/Text.hpp>

class Label : public Widget
{
public:
	Label();
	Label(const sf::String& string, const sf::Font& font, unsigned int characterSize = 30);

	template <class... Ts>
	static std::unique_ptr<Label> create(Ts&&... args)
	{
		return std::make_unique<Label>(std::forward<Ts>(args)...);
	}

	virtual sf::FloatRect getLocalBounds() const;
	sf::Text text;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
