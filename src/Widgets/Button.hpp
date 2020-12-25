#pragma once
#include "Widgets/Padding.hpp"
#include "Widgets/Widget.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Button : public Widget
{
public:
	Button();
	Button(const sf::String& string, const sf::Font& font, unsigned int characterSize = 30);
	Button(const sf::Vector2f& size);

	template <class... Ts>
	static std::unique_ptr<Button> create(Ts&&... args)
	{
		return std::make_unique<Button>(std::forward<Ts>(args)...);
	}

	virtual sf::FloatRect getLocalBounds() const;

	void setString(const sf::String& string);
	void setFont(const sf::Font& font);
	void setCharacterSize(unsigned int characterSize);

	void setBorderThickness(float borderThickness);
	void setSize(float rectWidth, float rectHeight);
	void setPadding(const Padding& padding);

	void setTextFillColor(const sf::Color& color);
	void setBackgroundColor(const sf::Color& color);
	void setBorderColor(const sf::Color& color);

	void updateLayout();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void setupDefaultStyle();

	sf::RectangleShape m_background;
	sf::Text m_text;
	Padding m_padding;
	bool m_fixedSize;
};
