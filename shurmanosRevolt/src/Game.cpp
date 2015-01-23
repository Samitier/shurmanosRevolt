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
	
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(Utils::pixelsToMeters(Vector2<int>(0, 570)).x, Utils::pixelsToMeters(Vector2<int>(0, 450)).y);
	b2Body* groundBody = engine.getWorld()->CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(800/PIXELS_METER, 30/PIXELS_METER);
	groundBody->CreateFixture(&groundBox, 0.0f);

	bkg.setTexture(*textureManager.getTexture(TextureManager::TEX_BACKGROUND));
	player.init(textureManager.getTexture(TextureManager::TEX_SPRITESHEET), Vector2<int>(400,0), engine.getWorld());
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

void Game::update() {
	player.update();
	engine.update();
	//updates aqui
}

void Game::render() {
	 window->clear();

	 window->draw(bkg);
	 player.render(window);
     if(debugRender) engine.getWorld()->DrawDebugData();
     //renders aqui
     
     window->display();
}

void Game::finalize() {

}


