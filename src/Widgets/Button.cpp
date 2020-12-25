#include "Button.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

Button::Button() :
	m_background{},
	m_text{},
	m_padding{},
	m_fixedSize{false}
{
}

Button::Button(const sf::String& string, const sf::Font& font, unsigned int characterSize) :
	m_background{},
	m_text{string, font, characterSize},
	m_padding{},
	m_fixedSize{false}
{
}

Button::Button(const sf::Vector2f& size) :
	m_background{size},
	m_text{},
	m_padding{},
	m_fixedSize{true}
{
}

sf::FloatRect Button::getLocalBounds() const
{
	return m_background.getGlobalBounds();
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

void Button::setBorderThickness(float outlineThickness)
{
	m_background.setOutlineThickness(outlineThickness);
}

void Button::setSize(float rectWidth, float rectHeight)
{
	m_fixedSize = true;
	m_background.setSize(sf::Vector2f(rectWidth, rectHeight));
}

void Button::setPadding(const Padding& padding)
{
	m_fixedSize = false;
	m_padding = padding;
}

void Button::setTextFillColor(const sf::Color& color)
{
	m_text.setFillColor(color);
}

void Button::setBackgroundColor(const sf::Color& color)
{
	m_background.setFillColor(color);
}

void Button::setBorderColor(const sf::Color& color)
{
	m_background.setOutlineColor(color);
}

void Button::updateLayout()
{
	const auto textBounds = m_text.getLocalBounds();
	if (!m_fixedSize)
	{
		m_background.setSize({
			textBounds.left + textBounds.width + m_padding.left + m_padding.right,
			textBounds.top + textBounds.height + m_padding.top + m_padding.bottom
		});
	}

	const auto size = m_background.getSize();
	const float borderThickness = m_background.getOutlineThickness();
	// TODO: center for fixed size
	const int textX = borderThickness + m_padding.left - textBounds.left / 2.f;
	const int textY = borderThickness + m_padding.top - textBounds.top / 2.f;

	m_background.setPosition(borderThickness, borderThickness);
	m_text.setPosition(textX, textY);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = nullptr;

	target.draw(m_background, states);
	target.draw(m_text, states);
}
