#pragma once
#include "Utils.h"
#include "Background.h"
#include "PhysicEntity.h"
#include "TextureManager.h"
#include "Camera.h"
#include"Building.h"

class Map {

public:
	Map(void);
	~Map(void);

	void init(TextureManager* textureManager, b2World* world, Camera* camera);
	void update(float deltaTime);
	void render(RenderWindow* window);

	int getWidth() { return mapWidth; }

private:
	Camera *camera; //we need the camera for knowing when to render the objects and for scrolling the background
	Background background; 
	PhysicEntity floor;
	//the building of the map
	Building building;
	//physicObjects of the map such as furniture, lightposts, and other details
	std::vector<PhysicEntity> objects;
	int mapWidth; //the total width of the map. A map always starts at x=0 and ends at x = width
};