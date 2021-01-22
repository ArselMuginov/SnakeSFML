#include "Gui.hpp"
#include "Widgets/Button.hpp"
#include "Widgets/HBox.hpp"
#include "Widgets/Label.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>

Gui::Gui(const sf::RenderWindow& parent, const Locale& locale) :
	c_parent{parent},
	c_fontHolder{},
	c_locale{locale},
	m_mainMenuBox{},
	m_gameBox{},
	m_mainDrawable{}
{
	sf::Vector2f parentSize{
		static_cast<float>(c_parent.getSize().x),
		static_cast<float>(c_parent.getSize().y)
	};

	m_mainMenuBox.setSize(parentSize);
	auto mainMenuBorder = VBox::create(sf::Vector2f{
		parentSize.x * 0.3f,
		parentSize.y * 0.7f
	});
	mainMenuBorder->setBorderThickness(1);

	auto title = Label::create(
		c_locale("main-menu", "game-title"),
		c_fontHolder[FontId::Default],
		c_titleCharacterSize
	);
	mainMenuBorder->add(std::move(title));

	auto buttonsGroup = VBox::create(sf::Vector2f{
		parentSize.x * 0.3f,
		parentSize.y * 0.6f
	});
	buttonsGroup->spacing = 10;

	auto startButton = Button::create(
		c_locale("main-menu", "start-game"),
		c_fontHolder[FontId::Default],
		c_buttonTextCharacterSize
	);
	startButton->setSize(150, 40);
	startButton->setBorderThickness(1);
	startButton->updateLayout();
	startButton->connect(
		sf::Event::MouseButtonPressed,
		[](sf::Event event) {
			std::cout << "Start button pressed" << std::endl;
		}
	);
	buttonsGroup->add(std::move(startButton));

	auto exitButton = Button::create(
		c_locale("main-menu", "exit-game"),
		c_fontHolder[FontId::Default],
		c_buttonTextCharacterSize
	);
	exitButton->setSize(150, 40);
	exitButton->setBorderThickness(1);
	exitButton->updateLayout();
	buttonsGroup->add(std::move(exitButton));

	buttonsGroup->updateLayout();
	mainMenuBorder->add(std::move(buttonsGroup));
	mainMenuBorder->updateLayout();

	m_mainMenuBox.add(std::move(mainMenuBorder));
	m_mainMenuBox.updateLayout();

	m_gameBox.setSize(parentSize);
	m_gameBox.spacing = 10;
	m_gameBox.setBorderThickness(1);
	m_gameBox.updateLayout();

	m_mainDrawable = &m_mainMenuBox;
}

void Gui::handleEvent(const sf::Event& event)
{
	m_mainDrawable->handleEvent(event);
}

void Gui::update()
{
}

void Gui::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = nullptr;
	target.draw(*m_mainDrawable, states);
}
