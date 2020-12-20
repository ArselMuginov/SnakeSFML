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

void Layout::addWidget(std::unique_ptr<Widget> element)
{
	m_children.push_back(std::move(element));
}

void Layout::removeWidget(std::size_t index)
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

void Layout::setSize(const sf::Vector2f& size)
{
	background.setSize(size);
}

const Widget& Layout::operator[](std::size_t index) const
{
	return *m_children[index];
}

void Layout::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = nullptr;

	target.draw(background, states);
	for (const auto& child : m_children)
	{
		target.draw(*child, states);
	}
}
