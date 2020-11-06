#pragma once
#include "Apple.hpp"
#include "GameScene.hpp"
#include "Snake.hpp"
#include "Localization/LocaleManager.hpp"
#include "TileMap/TileMap.hpp"
#include "TileMap/TileType.hpp"
#include "UI/Button.hpp"

namespace
{
	const unsigned int windowWidth = 640;
	const unsigned int windowHeight = 640;
	const unsigned int titleCharacterSize = 32;
	const unsigned int buttonTextCharacterSize = 24;
	const sf::Color backgroundColor(122, 168, 132);

	const unsigned int boardWidth = 20;
	const unsigned int boardHeight = 20;
	const sf::String tilesetFilename = L"../resources/Sprites/Tileset.png";
	const sf::Vector2u tileSize(32, 32);

	const std::string defaultLocaleKey = "en";
	const sf::String fontFilename = L"../resources/Fonts/NotoSansSC/Regular.otf";

	const GameScene firstScene = GameScene::MainMenu;

	const unsigned int snakeStartPos = boardWidth / 2 + boardHeight / 2 * boardWidth;
	const sf::Vector2i snakeStartDirection(1, 0);
	const unsigned int snakeStartLength = 2;
}

class Game
{
public:
	Game();

	void run();

private:
	void processEvents();
	void update();
	void render();

	// TODO: rename some variables so purpose is clear

	sf::RenderWindow m_window;
	LocaleManager m_localeManager;
	Locale m_locale;
	sf::RenderTexture m_renderTexture;
	sf::Font m_font;
	sf::RectangleShape m_mainMenuRect;
	sf::Text m_title;
	ui::Button m_startGameButton;
	ui::Button m_exitButton;
	sf::Texture m_tileset;
	TileMap m_tileMap;
	TileType m_boardState[boardWidth * boardHeight];
	const sf::Texture& m_texture;
	sf::Sprite m_sprite;
	GameScene m_activeScene;

	Snake m_snake;
	Apple m_apple;
};
