#pragma once
#include "GameScene.hpp"
#include "Gui.hpp"
#include "Localization/LocaleManager.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

namespace
{
	const unsigned int titleCharacterSize = 32;
	const unsigned int buttonTextCharacterSize = 24;

	const unsigned int boardWidth = 20;
	const unsigned int boardHeight = 20;
	const sf::String tilesetFilename = L"data/Sprites/Tileset.png";
	const sf::Vector2u tileSize(32, 32);

	const std::string defaultLocaleKey = "en";
	const sf::String fontFilename = L"data/Fonts/NotoSansSC/Regular.otf";
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

	static constexpr GameScene c_firstScene{GameScene::MainMenu};
	const sf::VideoMode c_videoMode{640, 640};
	const sf::Color c_backgroundColor{122, 168, 132};
	const std::string c_rootPath;

	sf::RenderWindow m_window;
	LocaleManager m_localeManager;
	Locale m_locale;
	Gui m_gui;
	GameScene m_activeScene;
};
