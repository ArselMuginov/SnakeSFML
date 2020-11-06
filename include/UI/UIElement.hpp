#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace ui
{
	class UIElement : public sf::Drawable, public sf::Transformable
	{
	public:
		virtual sf::FloatRect getLocalBounds() const = 0;
		sf::FloatRect getGlobalBounds() const;
	};
}
