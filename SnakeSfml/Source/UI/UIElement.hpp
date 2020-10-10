#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace ui
{
	class UIElement : public sf::Drawable, public sf::Transformable
	{
	};
}
