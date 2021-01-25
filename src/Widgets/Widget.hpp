#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Window/Event.hpp>

class Widget : public sf::Drawable, public sf::Transformable
{
public:
	virtual sf::FloatRect getLocalBounds() const = 0;
	sf::FloatRect getGlobalBounds() const;
	virtual void handleEvent(const sf::Event& event, const sf::Transform& globalTransform = {}) const;
};
