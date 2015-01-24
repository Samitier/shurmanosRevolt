#pragma once
#include "Utils.h"
#include "Background.h"
#include "PhysicEntity.h"
#include "TextureManager.h"

class Map {

public:
	Map(void);
	~Map(void);

	void init(TextureManager* textureManager, b2World* world);
	void update();
	void render(RenderWindow* window);

private:

	Background background;
	PhysicEntity floor;

};