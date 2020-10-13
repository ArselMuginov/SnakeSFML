#include "Game.hpp"
#include <random>

namespace
{
	template<typename T>
	void positionWithBounds(T& widget, float x, float y)
	{
		auto bounds = widget.getLocalBounds();
		int xBounded = x - bounds.width / 2 - bounds.left;
		int yBounded = y - bounds.height / 2 - bounds.top;
		widget.setPosition(xBounded, yBounded);
	}

	unsigned int getRandomEmptyTilePosition(TileType boardState[], int width, int height)
	{
		std::random_device rd;
		std::mt19937::result_type seed = rd();
		std::mt19937 rng(seed);
		std::uniform_int_distribution<std::mt19937::result_type> dist(0, width * height);
		unsigned int index;

		while (boardState[(index = dist(rng))] != TileType::Empty);

		return index;
	}
}

Game::Game() :
	m_window(),
	m_localeLoader(),
	m_renderTexture(),
	m_font(),
	m_mainMenuRect(sf::Vector2f(windowWidth * 0.5f, windowHeight * 0.7f)),
	m_title(),
	m_startGameButton(),
	m_exitButton(),
	m_tileset(),
	m_tileMap(m_tileset, tileSize, boardWidth, boardHeight),
	m_boardState(),
	m_texture(m_renderTexture.getTexture()),
	m_sprite(),
	m_activeScene(firstScene),
	m_snake(snakeStartPos, snakeStartDirection, snakeStartLength),
	m_apple(0)
{
	m_localeLoader.loadLocale(defaultLocaleKey);
	m_window.create(sf::VideoMode(windowWidth, windowHeight), m_localeLoader.getString(L"", L"window-title"), sf::Style::Titlebar | sf::Style::Close);

	if (!m_renderTexture.create(windowWidth, windowHeight))
	{
		throw "Unable to create render texture";
	}

	if (!m_font.loadFromFile(fontFilename))
	{
		throw "Unable to load font";
	}

	m_mainMenuRect.setPosition(windowWidth * 0.25f, windowHeight * 0.15f);
	m_mainMenuRect.setFillColor(sf::Color::Transparent);
	m_mainMenuRect.setOutlineThickness(1.f);
	m_mainMenuRect.setOutlineColor(sf::Color::Black);

	m_title.setString(m_localeLoader.getString(L"main-menu", L"game-title"));
	m_title.setFont(m_font);
	m_title.setFillColor(sf::Color::Black);
	positionWithBounds(m_title, windowWidth / 2, windowHeight * 0.2f);

	m_startGameButton.setString(m_localeLoader.getString(L"main-menu", L"start-game"));
	m_startGameButton.setFont(m_font);
	m_startGameButton.setCharacterSize(buttonTextCharacterSize);
	m_startGameButton.setBorderThickness(1.f);
	m_startGameButton.setSize(125.f, 30.f);
	m_startGameButton.setBackgroundColor(sf::Color::Transparent);
	m_startGameButton.setTextFillColor(sf::Color::Black);
	m_startGameButton.setBorderColor(sf::Color::Black);
	positionWithBounds(m_startGameButton, windowWidth / 2, windowHeight * 0.45f);

	m_exitButton.setString(m_localeLoader.getString(L"main-menu", L"exit-game"));
	m_exitButton.setFont(m_font);
	m_exitButton.setCharacterSize(buttonTextCharacterSize);
	m_exitButton.setBorderThickness(1.f);
	m_exitButton.setSize(125.f, 30.f);
	m_exitButton.setBackgroundColor(sf::Color::Transparent);
	m_exitButton.setTextFillColor(sf::Color::Black);
	m_exitButton.setBorderColor(sf::Color::Black);
	positionWithBounds(m_exitButton, windowWidth / 2, windowHeight * 0.55f);

	if (!m_tileset.loadFromFile(tilesetFilename))
	{
		throw "Unable to load tileset texture";
	}

	for (int i = 0; i < boardWidth * boardHeight; i++)
	{
		m_boardState[i] = TileType::Empty;
	}

	m_boardState[m_snake.headPosition] = TileType::SnakeHeadRight;
	m_apple.position = getRandomEmptyTilePosition(m_boardState, boardWidth, boardHeight);
	m_boardState[m_apple.position] = TileType::Apple;
	m_tileMap.tile(m_boardState);

	m_sprite.setTexture(m_texture);
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

		switch (m_activeScene)
		{
			case GameScene::MainMenu:
			{
				switch (event.type)
				{
					case sf::Event::MouseButtonReleased:
					{
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							auto mousePos = sf::Mouse::getPosition(m_window);
							if (m_startGameButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
							{
								m_activeScene = GameScene::Game;
							}
							else if (m_exitButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
							{
								m_window.close();
							}
						}
						break;
					}
				}
				break;
			}
			case GameScene::Game:
			{
				break;
			}
			default:
			{
				throw "Enum corruption";
			}
		}
	}
}

void Game::update()
{
	if (m_activeScene == GameScene::Game)
	{

	}
}

void Game::render()
{
	m_renderTexture.clear(backgroundColor);
	switch (m_activeScene)
	{
		case GameScene::MainMenu:
		{
			m_renderTexture.draw(m_mainMenuRect);
			m_renderTexture.draw(m_title);
			m_renderTexture.draw(m_startGameButton);
			m_renderTexture.draw(m_exitButton);
			break;
		}

		case GameScene::Game:
		{
			m_renderTexture.draw(m_tileMap);
			break;
		}

		default:
		{
			throw "Enum corruption";
		}
	}
	m_renderTexture.display();

	m_window.clear();
	m_window.draw(m_sprite);
	m_window.display();
}
