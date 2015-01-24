#pragma once
#include "Includes.h"
#include "TextureManager.h"
#include "PhysicsEngine.h"
#include "PhysicEntity.h"
#include "Player.h" 
#include "DebugDraw.h"
#include "Map.h"
#include "Camera.h"

class Game {
public:
	Game(void);
	~Game(void);

	void init();
	void mainLoop();
	void finalize();

	void processInput();
	void update(float deltaTime);
	void render();

private:
	RenderWindow* window;
	TextureManager textureManager;
    
    //Is Debug drawing active?
    bool debugRender; 

	///only for testing
	PhysicsEngine engine;
	Camera camera;
	Map map;
	Player player;

};

