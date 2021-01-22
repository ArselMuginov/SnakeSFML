#include "Game.hpp"
#include "Utility/Paths.hpp"
#include <SFML/Window/Event.hpp>

Game::Game() :
	m_locale{c_startupLocaleKey},
	m_window{c_videoMode, m_locale("", "window-title"), sf::Style::Titlebar | sf::Style::Close},
	m_gui{m_window, m_locale},
	m_activeScene{c_firstScene}
{
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
