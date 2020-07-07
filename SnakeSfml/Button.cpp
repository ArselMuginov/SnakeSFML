#include "Button.hpp"

// TODO: ensure to call resize rect stuff after setting font and string?

Button::Button() : m_border(), m_text(), m_borderOutlineThickness(1.f)
{
}

Button::~Button()
{
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = NULL;

	target.draw(m_text, states);
	target.draw(m_border, states);
}

sf::FloatRect Button::getLocalBounds() const
{
	return m_border.getGlobalBounds();
}

sf::FloatRect Button::getGlobalBounds() const
{
	return getTransform().transformRect(getLocalBounds());
}

void Button::setString(const sf::String& string)
{
	m_text.setString(string);
}

void Button::setFont(const sf::Font& font)
{
	m_text.setFont(font);
}

void Button::setCharacterSize(unsigned int characterSize)
{
	m_text.setCharacterSize(characterSize);
}

void Button::setBorderOutlineThickness(float outlineThickness)
{
	m_borderOutlineThickness = outlineThickness;
	m_border.setOutlineThickness(outlineThickness);
}

void Button::setBorderSize(float rectWidth, float rectHeight)
{
	auto textBounds = m_text.getLocalBounds();
	int textX = m_borderOutlineThickness - textBounds.left + (rectWidth - textBounds.width) / 2;
	int textY = m_borderOutlineThickness - textBounds.top + (rectHeight - textBounds.height) / 2;
	m_text.setPosition(textX, textY);

	m_border.setSize(sf::Vector2f(rectWidth, rectHeight));
	m_border.setPosition(m_borderOutlineThickness, m_borderOutlineThickness);
}

void Button::setPadding(float paddingX, float paddingY)
{
	auto textBounds = m_text.getLocalBounds();
	m_text.setPosition(m_borderOutlineThickness + paddingX - textBounds.left / 2, m_borderOutlineThickness + paddingY - textBounds.top / 2);

	m_border.setPosition(m_borderOutlineThickness, m_borderOutlineThickness);
	m_border.setSize(sf::Vector2f(textBounds.left + textBounds.width + paddingX * 2, textBounds.top + textBounds.height + paddingY * 2));
}

void Button::setTextFillColor(sf::Color color)
{
	m_text.setFillColor(color);
}

void Button::setBorderFillColor(sf::Color color)
{
	m_border.setFillColor(color);
}

void Button::setBorderOutlineColor(sf::Color color)
{
	m_border.setOutlineColor(color);
}
