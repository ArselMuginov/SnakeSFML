#include "Gui.hpp"
#include "Widgets/Button.hpp"

Gui::Gui(std::string_view rootPath, const Locale& locale) :
	c_fontHolder{rootPath},
	c_locale{locale},
	m_mainMenuBox{},
	m_gameBox{},
	m_mainDrawable{}
{
	m_mainMenuBox.setStyle(Layout::Style::BlackBorder);
	m_mainMenuBox.setPosition(10, 10);
	m_mainMenuBox.setSize({100, 200});

	auto startButton = Button::create(
		c_locale({"main-menu", "start-game"}),
		c_fontHolder[FontId::Default],
		c_buttonTextCharacterSize
	);
	startButton->setSize(10, 10);
	startButton->setStyle(Button::Style::BlackOutline);
	m_mainMenuBox.addWidget(std::move(startButton));

	auto exitButton = Button::create(
		c_locale({"main-menu", "exit-game"}),
		c_fontHolder[FontId::Default],
		c_buttonTextCharacterSize
	);
	exitButton->setSize(10, 10);
	exitButton->setStyle(Button::Style::BlackOutline);
	m_mainMenuBox.addWidget(std::move(exitButton));

	m_gameBox.setStyle(Layout::Style::BlackBorder);
	m_gameBox.setPosition(10, 10);
	m_gameBox.setSize({200, 100});

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
	target.draw(*m_mainDrawable, states);
}
