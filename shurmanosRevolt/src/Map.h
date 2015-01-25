#pragma once
#include "Utils.h"
#include "Background.h"
#include "PhysicEntity.h"
#include "TextureManager.h"
#include "Camera.h"

class Map {

public:
	Map(void);
	~Map(void);

	void init(TextureManager* textureManager, b2World* world, Camera* camera);
	void update(float deltaTime);
	void render(RenderWindow* window);

	int getWidth() { return mapWidth; }

private:
	Camera *camera;
	Background background;
	PhysicEntity floor;
	int mapWidth;
};