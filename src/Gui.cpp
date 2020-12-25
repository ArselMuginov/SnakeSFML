#include "Gui.hpp"
#include "Widgets/Button.hpp"
#include "Widgets/HBox.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

Gui::Gui(const sf::RenderWindow& parent, std::string_view rootPath, const Locale& locale) :
	c_parent{parent},
	c_fontHolder{rootPath},
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
	auto mainMenuCenter = VBox::create(sf::Vector2f{
		parentSize.x * 0.3f,
		parentSize.y * 0.7f
	});
	mainMenuCenter->spacing = 10;
	mainMenuCenter->setBorderThickness(1);

	auto startButton = Button::create(
		c_locale("main-menu", "start-game"),
		c_fontHolder[FontId::Default],
		c_buttonTextCharacterSize
	);
	//startButton->setSize(150, 40);
	startButton->setBorderThickness(1);
	startButton->updateLayout();
	mainMenuCenter->add(std::move(startButton));

	auto exitButton = Button::create(
		c_locale("main-menu", "exit-game"),
		c_fontHolder[FontId::Default],
		c_buttonTextCharacterSize
	);
	//exitButton->setSize(150, 40);
	exitButton->setBorderThickness(1);
	exitButton->updateLayout();
	mainMenuCenter->add(std::move(exitButton));

	mainMenuCenter->updateLayout();
	m_mainMenuBox.add(std::move(mainMenuCenter));
	m_mainMenuBox.updateLayout();

	m_gameBox.setSize(parentSize);
	m_gameBox.spacing = 10;
	m_gameBox.setBorderThickness(1);
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
