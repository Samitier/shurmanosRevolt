#include "Game.h"

int main()
{
	Game game;
	game.init();
	game.mainLoop();
	game.finalize();

    return 0;
}