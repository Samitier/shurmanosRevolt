#include "Game.h"


Game::Game(void) { }
Game::~Game(void) { }


void Game::init() {
	window = new RenderWindow(VideoMode(800, 600), "Shurmanos Revolt");
	window->setVerticalSyncEnabled(true); //forces 60fps

    //For now the physics engine doesn't know about the debug drawer.
    engine.getWorld()->SetDebugDraw(new DebugDraw(window));
    
    debugRender = false;
    
	textureManager.init();
	
	map.init(&textureManager,engine.getWorld());

	player.init(textureManager.getTexture(TextureManager::TEX_SPRITESHEET), Vector2<int>(200,0), engine.getWorld());
	camera.init(window, &player);
}

void Game::mainLoop() {
    Clock clock;
    Time t = clock.getElapsedTime();
    while (window->isOpen()) {
        float deltaTime = (clock.getElapsedTime() - t).asSeconds();
        t = clock.getElapsedTime();
		processInput();
		update(deltaTime);
		render();
    }
	finalize();
}

void Game::processInput() {
	Event event;
    while (window->pollEvent(event)) {
        switch(event.type) {
            case sf::Event::KeyPressed:
            if(event.key.code == Keyboard::F2) debugRender = !debugRender;                
            break;
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

void Game::update(float deltaTime) {
	map.update(deltaTime);
	player.update(deltaTime);
	camera.update(deltaTime);
	engine.update(deltaTime);
}

void Game::render() {
	 window->clear();

	 map.render(window);
	 player.render(window);
     if(debugRender) engine.getWorld()->DrawDebugData();
     
     window->display();
}

void Game::finalize() {

}


