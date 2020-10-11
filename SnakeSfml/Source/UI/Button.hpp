#pragma once
#include "UIElement.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace ui
{
	class Button : public UIElement
	{
	public:
		Button();

		sf::FloatRect getLocalBounds() const;
		sf::FloatRect getGlobalBounds() const;
		void setString(const sf::String& string);
		void setFont(const sf::Font& font);
		void setCharacterSize(unsigned int characterSize);
		void setBorderOutlineThickness(float outlineThickness);
		void setBorderSize(float rectWidth, float rectHeight);
		void setPadding(float paddingX, float paddingY);
		void setTextFillColor(sf::Color color);
		void setBorderFillColor(sf::Color color);
		void setBorderOutlineColor(sf::Color color);

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		sf::RectangleShape m_border;
		sf::Text m_text;
		float m_borderOutlineThickness;
	};
}
