#pragma once
#include "Resource/FontHolder.hpp"
#include "Widgets/Button.hpp"
#include "Widgets/Text.hpp"
#include "Widgets/VBox.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>

class Gui : public sf::Drawable
{
public:
	Gui(const std::string& rootPath);

	void handleInput(const sf::Event& event);
	void update();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	static constexpr unsigned int c_titleCharacterSize{32};
	static constexpr unsigned int c_buttonTextCharacterSize{24};

	const sf::Color c_backgroundColor{122, 168, 132};

	const FontHolder c_fontHolder;

	VBox m_mainMenuBox;
	Text m_title;
	Button m_startButton;
	Button m_exitButton;
	sf::Drawable* m_mainDrawable;
};
