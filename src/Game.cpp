#include "Game.hpp"
#include <SFML/Window/Event.hpp>

Game::Game() :
	m_locale{c_startupLocaleKey},
	m_window{c_videoMode, m_locale("", "window-title"), sf::Style::Titlebar | sf::Style::Close},
	m_activeScene{c_firstScene},
	m_gui{m_window, m_locale, m_activeScene}
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

		m_gui.handleEvent(event);
	}
}

void Game::update()
{
	m_gui.update();
}

void Game::render()
{
	m_window.clear();

	switch (m_activeScene)
	{
	case GameScene::MainMenu:
		break;
	case GameScene::Game:
		break;
	default:
		throw std::domain_error{"Bad enum value"};
	}

	m_window.draw(m_gui);
	m_window.display();
}
