#pragma once
#include "Includes.h"
#include "TextureManager.h"
#include "PhysicsEngine.h"
#include "PhysicEntity.h"
#include "Player.h" 
#include "DebugDraw.h"

class Game {
public:
	Game(void);
	~Game(void);

	void init();
	void mainLoop();
	void finalize();

	void processInput();
	void update();
	void render();

private:
	RenderWindow* window;
	TextureManager textureManager;
    
    //Is Debug drawing active?
    bool debugRender; 

	///only for testing
	PhysicsEngine engine;
	Sprite bkg;
	Player player;
	PhysicEntity floor;

};

