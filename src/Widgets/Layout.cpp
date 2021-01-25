#include "Layout.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

Layout::Layout(const sf::Vector2f& size) :
	padding{},
	spacing{0},
	m_children{},
	m_background{size}
{
	setBackgroundColor(sf::Color::Transparent);
	setBorderColor(sf::Color::White);
}

void Layout::add(std::unique_ptr<Widget> element)
{
	m_children.push_back(std::move(element));
}

void Layout::remove(std::size_t index)
{
	m_children.erase(std::next(m_children.begin(), index));
}

sf::FloatRect Layout::getLocalBounds() const
{
	return m_background.getGlobalBounds();
}

void Layout::setSize(const sf::Vector2f& size)
{
	m_background.setSize(size);
}

void Layout::setBorderThickness(float borderThickness)
{
	m_background.setOutlineThickness(borderThickness);
}

void Layout::setBackgroundColor(const sf::Color& color)
{
	m_background.setFillColor(color);
}

void Layout::setBorderColor(const sf::Color& color)
{
	m_background.setOutlineColor(color);
}

void Layout::handleEvent(const sf::Event& event, const sf::Transform& globalTransform) const
{
	const auto newTransform = globalTransform * getTransform();

	for (const auto& child : m_children)
	{
		child->handleEvent(event, newTransform);
	}
}

const Widget& Layout::operator[](std::size_t index) const
{
	return *m_children[index];
}

void Layout::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = nullptr;

	target.draw(m_background, states);
	for (const auto& child : m_children)
	{
		target.draw(*child, states);
	}
}
