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
	m_mainMenuBox.spacing = 10;
	m_mainMenuBox.setBackgroundColor(sf::Color::Transparent);
	m_mainMenuBox.setBorderThickness(1);
	m_mainMenuBox.setBorderColor(sf::Color::White);

	auto startButton = Button::create(
		c_locale("main-menu", "start-game"),
		c_fontHolder[FontId::Default],
		c_buttonTextCharacterSize
	);
	//startButton->setSize(150, 40);
	startButton->setBackgroundColor(sf::Color::Transparent);
	startButton->setBorderThickness(1);
	startButton->setBorderColor(sf::Color::White);
	startButton->updateLayout();
	m_mainMenuBox.add(std::move(startButton));

	auto exitButton = Button::create(
		c_locale("main-menu", "exit-game"),
		c_fontHolder[FontId::Default],
		c_buttonTextCharacterSize
	);
	//exitButton->setSize(150, 40);
	exitButton->setBackgroundColor(sf::Color::Transparent);
	exitButton->setBorderThickness(1);
	exitButton->setBorderColor(sf::Color::White);
	exitButton->updateLayout();
	m_mainMenuBox.add(std::move(exitButton));

	m_mainMenuBox.updateLayout();

	m_gameBox.spacing = 10;
	m_gameBox.setBackgroundColor(sf::Color::Transparent);
	m_gameBox.setBorderThickness(1);
	m_gameBox.setBorderColor(sf::Color::White);
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
