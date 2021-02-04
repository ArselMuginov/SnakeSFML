#pragma once
#include "GameScene.hpp"
#include "Gui.hpp"
#include "Localization/Locale.hpp"
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
	static constexpr std::string_view c_startupLocaleKey{"en"};
	const sf::VideoMode c_videoMode{640, 640};
	const sf::Color c_backgroundColor{122, 168, 132};

	Locale m_locale;
	sf::RenderWindow m_window;
	GameScene m_activeScene;
	Gui m_gui;
};
