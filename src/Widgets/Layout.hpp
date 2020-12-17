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

	template <class... Ts>
	static std::unique_ptr<Layout> create(Ts&&... args);

	void addElement(std::unique_ptr<Widget> element);
	void removeElement(std::size_t index);
	virtual void update() = 0;
	virtual sf::FloatRect getLocalBounds() const;
	void setStyle(Style style);

	const Widget& operator[](std::size_t index) const;

	Padding padding;
	float margin;
	bool stretchContent;
	sf::RectangleShape background;

protected:
	std::vector<std::unique_ptr<Widget>> m_children;
};
