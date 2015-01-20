#pragma once
#include "Includes.h"
#include "TextureManager.h"
#include "PhysicsEngine.h"
#include "PhysicEntity.h"

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

	///only for testing
	PhysicsEngine engine;
	Sprite bkg;
	PhysicEntity tank;
	PhysicEntity floor;

};

