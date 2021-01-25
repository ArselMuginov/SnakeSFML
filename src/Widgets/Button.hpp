#pragma once
#include "Widgets/Padding.hpp"
#include "Widgets/Widget.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <functional>
#include <vector>
#include <unordered_map>

class Button : public Widget
{
public:
	enum class Signal
	{
		Pressed
	};

	Button(const sf::String& string, const sf::Font& font, unsigned int characterSize = 30);

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

	void connect(Signal signal, std::function<void()> function);
	virtual void handleEvent(const sf::Event& event, const sf::Transform& globalTransform = {}) const;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::RectangleShape m_background;
	sf::Text m_text;
	Padding m_padding;
	bool m_fixedSize;
	std::unordered_map<Signal, std::vector<std::function<void()>>> m_eventHandler;
};
