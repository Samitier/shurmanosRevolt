#include "Game.h"


Game::Game(void) { }
Game::~Game(void) { }


void Game::init() {
	window = new RenderWindow(VideoMode(800, 600), "Shurmanos Revolt");
	window->setVerticalSyncEnabled(true); //forces 60fps
	
	textureManager.init();

	bkg.setTexture(*textureManager.getTexture(TextureManager::TEX_BACKGROUND));
}

void Game::mainLoop() {
    while (window->isOpen()) {
		processInput();
		update();
		render();
    }
	finalize();
}

void Game::processInput() {
	Event event;
    while (window->pollEvent(event)) {
        switch(event.type) {
		case sf::Event::Closed: 
			window->close();
			break;
		case sf::Event::Resized:
			//resize camera i tal
			break;
		}
    } 
	//inputs aqui
}

void Game::update() {
	//updates aqui
}

void Game::render() {
	 window->clear();

	 window->draw(bkg);
     //renders aqui

     window->display();
}

void Game::finalize() {

}


