#include "Map.h"


Map::Map(void){}
Map::~Map(void){}

void Map::init(TextureManager *textureManager,  b2World* world) {
	//hardcoded example. In reality, there must be a "loadLevel" function that reads the level from a file.
	floor.init(textureManager->getTexture(TextureManager::TEX_FLOOR),Vector2<int>(0,SCREEN_HEIGHT-(22/2)),Vector2<int>(2108,22));
	b2PolygonShape shape;
	float w =2108/PIXELS_METER;
    float h = 22/PIXELS_METER;
	shape.SetAsBox(w/2,h/2);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 1.5f;
	std::vector<b2FixtureDef*> fd;
	fd.push_back(&fixtureDef);
	floor.setPhysics(world,&fd,true,true);
	
	std::vector<Texture*> texturesBackground;
	texturesBackground.push_back(textureManager->getTexture(TextureManager::TEX_BKG01));
	texturesBackground.push_back(textureManager->getTexture(TextureManager::TEX_BKG02));
	texturesBackground.push_back(textureManager->getTexture(TextureManager::TEX_BKG03));
	background.init(texturesBackground);

}

void Map::update(float deltaTime) {
	background.update(deltaTime);
}

void Map::render(RenderWindow *window) {
	background.render(window);
	floor.render(window);
}