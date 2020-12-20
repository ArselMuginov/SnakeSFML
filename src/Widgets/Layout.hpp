#pragma once
#include "Widgets/Padding.hpp"
#include "Widgets/Widget.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <cstddef>
#include <memory>
#include <vector>

class Layout : public Widget
{
public:
	enum class Style
	{
		Invisible,
		WhiteBorder,
		BlackBorder
	};

	Layout();
	Layout(const sf::Vector2f& size);

	void addWidget(std::unique_ptr<Widget> element);
	void removeWidget(std::size_t index);
	virtual void update() = 0;
	virtual sf::FloatRect getLocalBounds() const;
	void setStyle(Style style);
	void setSize(const sf::Vector2f& size);

	const Widget& operator[](std::size_t index) const;

	Padding padding;
	float margin;
	bool stretchContent;
	sf::RectangleShape background;

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	std::vector<std::unique_ptr<Widget>> m_children;
};
