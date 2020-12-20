#include "Game.hpp"
#include "whereami/wrapper.hpp"
#include <SFML/Window/Event.hpp>
#include <random>

Game::Game() :
	c_rootPath{wai::getExecutablePath() + "\\..\\"},
	m_window{},
	m_localeManager{c_rootPath},
	m_locale{m_localeManager.getLocalePath(c_defaultLocaleKey)},
	m_gui{c_rootPath, m_locale},
	m_activeScene{c_firstScene}
{
	m_window.create(
		c_videoMode,
		m_locale({"", "window-title"}),
		sf::Style::Titlebar | sf::Style::Close
	);
}

void Game::run()
{
	while (m_window.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
			continue;
		}

		m_gui.handleInput(event);
	}
}

void Game::update()
{
	m_gui.update();
}

void Game::render()
{
	m_window.clear();
	m_window.draw(m_gui);
	m_window.display();
}
