#include "Game.hpp"
#include <iostream>

// TODO: graphic and logic to select buttons by keyboard
// TODO: graphic for mouse hover and click
// TODO: what to do with locale agnostic strings like window-title?
// TODO: graceful error handling
// TODO: group GUI elements?
// TODO: refactor GUI positioning to be more clear
// TODO: finish game logic
// TODO: add localized locale names and a way to choose locale
// TODO: location of executable

int main()
{
	try
	{
		Game game;
		game.run();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
