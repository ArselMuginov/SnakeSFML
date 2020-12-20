#pragma once
#include "Localization/Locale.hpp"
#include "Resource/FontHolder.hpp"
#include "Widgets/HBox.hpp"
#include "Widgets/VBox.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>

class Gui : public sf::Drawable
{
public:
	Gui(std::string_view rootPath, const Locale& locale);

	void handleInput(const sf::Event& event);
	void update();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	static constexpr unsigned int c_titleCharacterSize{32};
	static constexpr unsigned int c_buttonTextCharacterSize{24};
	const sf::Color c_backgroundColor{122, 168, 132};
	const FontHolder c_fontHolder;
	const Locale& c_locale;

	VBox m_mainMenuBox;
	HBox m_gameBox;
	sf::Drawable* m_mainDrawable;
};
