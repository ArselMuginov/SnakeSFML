#include "Widget.hpp"

Widget::Widget() : m_eventHandler{}
{
	for (int eventType = 0; eventType != sf::Event::Count; eventType++)
	{
		m_eventHandler.insert({static_cast<sf::Event::EventType>(eventType), {}});
	}
}

sf::FloatRect Widget::getGlobalBounds() const
{
	return getTransform().transformRect(getLocalBounds());
}

void Widget::connect(sf::Event::EventType eventType, HandlerFunction function)
{
	m_eventHandler[eventType].push_back(function);
}

void Widget::handleEvent(const sf::Event& event, const sf::Transform& globalTransform)
{
	for (auto& function : m_eventHandler[event.type])
	{
		std::invoke(function, event, this, globalTransform * getTransform());
	}
}
