#pragma once
#include "Padding.hpp"
#include "UIElement.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace ui
{
	class Button : public UIElement
	{
	public:
		enum class Style
		{
			WhiteOutline,
			BlackOutline
		};

		Button();
		Button(const sf::String& string, const sf::Font& font, unsigned int characterSize = 30);
		Button(const sf::Vector2f& size);

		virtual sf::FloatRect getLocalBounds() const;

		void setString(const sf::String& string);
		void setFont(const sf::Font& font);
		void setCharacterSize(unsigned int characterSize);
		
		void setBorderThickness(float borderThickness);
		void setSize(float rectWidth, float rectHeight);
		void setPadding(const Padding& padding);
		
		void setTextFillColor(sf::Color color);
		void setBackgroundColor(sf::Color color);
		void setBorderColor(sf::Color color);

		void setStyle(Style style);

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void update();

		sf::RectangleShape m_background;
		sf::Text m_text;
		Padding m_padding;
		bool m_fixedSize;
	};
}
