#pragma once
#include "Widgets/Padding.hpp"
#include "Widgets/Widget.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <cstddef>
#include <memory>
#include <vector>

class Layout : public Widget
{
public:
	Layout(const sf::Vector2f& size = sf::Vector2f{});

	void add(std::unique_ptr<Widget> element);
	void remove(std::size_t index);
	virtual void updateLayout() = 0;
	
	virtual sf::FloatRect getLocalBounds() const;
	void setSize(const sf::Vector2f& size);
	void setBorderThickness(float borderThickness);

	void setBackgroundColor(const sf::Color& color);
	void setBorderColor(const sf::Color& color);

	virtual void handleEvent(const sf::Event& event, const sf::Transform& globalTransform = {}) const;

	const Widget& operator[](std::size_t index) const;

	Padding padding;
	float spacing;

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	std::vector<std::unique_ptr<Widget>> m_children;
	sf::RectangleShape m_background;
};
