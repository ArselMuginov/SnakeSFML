#include "UIElement.hpp"

namespace ui
{
	sf::FloatRect UIElement::getGlobalBounds() const
	{
		return getTransform().transformRect(getLocalBounds());
	}
}
