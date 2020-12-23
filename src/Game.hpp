#pragma once
#include "GameScene.hpp"
#include "Gui.hpp"
#include "Localization/LocaleManager.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

class Game
{
public:
	Game();

	void run();

private:
	void processEvents();
	void update();
	void render();

	static constexpr GameScene c_firstScene{GameScene::MainMenu};
	static constexpr std::string_view c_defaultLocaleKey{"en"};
	const sf::VideoMode c_videoMode{640, 640};
	const sf::Color c_backgroundColor{122, 168, 132};
	const std::string c_rootPath;

	LocaleManager m_localeManager;
	Locale m_locale;
	sf::RenderWindow m_window;
	Gui m_gui;
	GameScene m_activeScene;
};
