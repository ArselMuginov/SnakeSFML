#include "Widget.hpp"

Widget::Widget() : m_eventHandler{}
{
}

sf::FloatRect Widget::getGlobalBounds() const
{
	return getTransform().transformRect(getLocalBounds());
}

void Widget::connect(sf::Event::EventType eventType, std::function<void(sf::Event)> function)
{
	m_eventHandler.insert({eventType, {}});
	m_eventHandler[eventType].push_back(function);
}

void Widget::handleEvent(const sf::Event& event)
{
	for (auto& function : m_eventHandler[event.type])
	{
		std::invoke(function, event);
	}
}
