#include "Widget.hpp"

sf::FloatRect Widget::getGlobalBounds() const
{
	return getTransform().transformRect(getLocalBounds());
}

void Widget::handleEvent(const sf::Event& event, const sf::Transform& globalTransform) const
{
}
