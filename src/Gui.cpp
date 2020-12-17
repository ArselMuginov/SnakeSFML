#include "Gui.hpp"

Gui::Gui(const std::string& rootPath) :
	c_fontHolder{rootPath},
	m_mainMenuBox{},
	m_title{},
	m_startButton{},
	m_exitButton{},
	m_mainDrawable{}
{
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
