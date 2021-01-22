#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Window/Event.hpp>
#include <functional>
#include <unordered_map>
#include <vector>

class Widget : public sf::Drawable, public sf::Transformable
{
public:
	Widget();

	virtual sf::FloatRect getLocalBounds() const = 0;
	sf::FloatRect getGlobalBounds() const;
	void connect(sf::Event::EventType eventType, std::function<void(sf::Event)> function);
	virtual void handleEvent(const sf::Event& event);

protected:
	std::unordered_map<sf::Event::EventType, std::vector<std::function<void(sf::Event)>>> m_eventHandler;
};
