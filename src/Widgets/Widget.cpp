#include "Widget.hpp"

sf::FloatRect Widget::getGlobalBounds() const
{
	return getTransform().transformRect(getLocalBounds());
}
