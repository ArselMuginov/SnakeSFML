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
	typedef std::function<void(const sf::Event&, const Widget*, const sf::Transform&)> HandlerFunction;

	Widget();

	virtual sf::FloatRect getLocalBounds() const = 0;
	sf::FloatRect getGlobalBounds() const;
	void connect(sf::Event::EventType eventType, HandlerFunction function);
	virtual void handleEvent(const sf::Event& event, const sf::Transform& globalTransform = {});

protected:
	std::unordered_map<sf::Event::EventType, std::vector<HandlerFunction>> m_eventHandler;
};
