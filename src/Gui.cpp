#include "Gui.hpp"
#include "Widgets/Button.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

Gui::Gui(const sf::RenderWindow& parent, std::string_view rootPath, const Locale& locale) :
	c_parent{parent},
	c_fontHolder{rootPath},
	c_locale{locale},
	m_mainMenuBox{{200, 400}},
	m_gameBox{{200, 100}},
	m_mainDrawable{}
{
	m_mainMenuBox.setStyle(Layout::Style::WhiteBorder);
	m_mainMenuBox.setPosition(10, 10);
	m_mainMenuBox.spacing = 10;

	auto startButton = Button::create(
		c_locale("main-menu", "start-game"),
		c_fontHolder[FontId::Default],
		c_buttonTextCharacterSize
	);
	//startButton->setSize(150, 40);
	startButton->setStyle(Button::Style::WhiteOutline);
	startButton->updateLayout();
	m_mainMenuBox.add(std::move(startButton));

	auto exitButton = Button::create(
		c_locale("main-menu", "exit-game"),
		c_fontHolder[FontId::Default],
		c_buttonTextCharacterSize
	);
	//exitButton->setSize(150, 40);
	exitButton->setStyle(Button::Style::WhiteOutline);
	exitButton->updateLayout();
	m_mainMenuBox.add(std::move(exitButton));

	m_mainMenuBox.updateLayout();

	m_gameBox.setStyle(Layout::Style::WhiteBorder);
	m_gameBox.setPosition(10, 10);
	m_gameBox.updateLayout();

	m_mainDrawable = &m_mainMenuBox;
}

void Gui::handleInput(const sf::Event& event)
{
}

void Gui::update()
{
}

void Gui::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = nullptr;
	target.draw(m_mainMenuBox, states);
}
