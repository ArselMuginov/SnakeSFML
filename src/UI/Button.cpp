#include "UI/Button.hpp"

// TODO: ensure to call resize rect stuff after setting font and string?

namespace ui
{
	Button::Button() :
		m_background(),
		m_text(),
		m_padding(),
		m_fixedSize(false)
	{
	}

	Button::Button(const sf::String& string, const sf::Font& font, unsigned int characterSize) :
		m_background(),
		m_text(string, font, characterSize),
		m_padding(),
		m_fixedSize(false)
	{
		update();
	}

	Button::Button(const sf::Vector2f& size) :
		m_background(size),
		m_text(),
		m_padding(),
		m_fixedSize(true)
	{
		update();
	}

	template <class... Ts>
	std::unique_ptr<Button> Button::create(Ts&&... args)
	{
		return std::make_unique<Button>(std::forward<Ts>(args)...);
	}

	sf::FloatRect Button::getLocalBounds() const
	{
		return m_background.getGlobalBounds();
	}

	void Button::setString(const sf::String& string)
	{
		m_text.setString(string);
		update();
	}

	void Button::setFont(const sf::Font& font)
	{
		m_text.setFont(font);
		update();
	}

	void Button::setCharacterSize(unsigned int characterSize)
	{
		m_text.setCharacterSize(characterSize);
		update();
	}

	void Button::setBorderThickness(float outlineThickness)
	{
		m_background.setOutlineThickness(outlineThickness);
		update();
	}

	void Button::setSize(float rectWidth, float rectHeight)
	{
		m_fixedSize = true;
		m_background.setSize(sf::Vector2f(rectWidth, rectHeight));
		update();
	}

	void Button::setPadding(const Padding& padding)
	{
		m_fixedSize = false;
		m_padding = padding;
		update();
	}

	void Button::setTextFillColor(sf::Color color)
	{
		m_text.setFillColor(color);
	}

	void Button::setBackgroundColor(sf::Color color)
	{
		m_background.setFillColor(color);
	}

	void Button::setBorderColor(sf::Color color)
	{
		m_background.setOutlineColor(color);
	}

	void Button::setStyle(Style style)
	{
		switch (style)
		{
			case Style::WhiteOutline:
				m_background.setFillColor(sf::Color::Transparent);
				m_background.setOutlineColor(sf::Color::White);
				m_background.setOutlineThickness(1);
				m_text.setFillColor(sf::Color::White);
				break;

			case Style::BlackOutline:
				m_background.setFillColor(sf::Color::Transparent);
				m_background.setOutlineColor(sf::Color::Black);
				m_background.setOutlineThickness(1);
				m_text.setFillColor(sf::Color::Black);
				break;

			default:
				break;
		}
	}

	void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		states.texture = nullptr;

		target.draw(m_background, states);
		target.draw(m_text, states);
	}

	void Button::update()
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
}
