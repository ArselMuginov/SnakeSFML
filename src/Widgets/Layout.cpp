#include "Layout.hpp"

Layout::Layout() :
	padding(),
	margin(0),
	stretchContent(false),
	background(),
	m_children()
{
}

Layout::Layout(const sf::Vector2f& size) :
	padding(),
	margin(0),
	stretchContent(false),
	background(size),
	m_children()
{
}

template <class... Ts>
std::unique_ptr<Layout> Layout::create(Ts&&... args)
{
	return std::make_unique<Layout>(std::forward<Ts>(args)...);
}

void Layout::addElement(std::unique_ptr<Widget> element)
{
	m_children.push_back(std::move(element));
}

void Layout::removeElement(std::size_t index)
{
	m_children.erase(std::next(m_children.begin(), index));
}

sf::FloatRect Layout::getLocalBounds() const
{
	return background.getLocalBounds();
}

void Layout::setStyle(Style style)
{
	switch (style)
	{
		case Style::Invisible:
			background.setFillColor(sf::Color::Transparent);
			background.setOutlineThickness(0);
			break;

		case Style::WhiteBorder:
			background.setFillColor(sf::Color::Transparent);
			background.setOutlineColor(sf::Color::White);
			background.setOutlineThickness(1);
			break;

		case Style::BlackBorder:
			background.setFillColor(sf::Color::Transparent);
			background.setOutlineColor(sf::Color::Black);
			background.setOutlineThickness(1);
			break;

		default:
			break;
	}
}

const Widget& Layout::operator[](std::size_t index) const
{
	return *m_children[index];
}
