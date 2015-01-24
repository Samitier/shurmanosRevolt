#include "Map.h"


Map::Map(void){}
Map::~Map(void){}

void Map::init(TextureManager *textureManager,  b2World* world) {
	//hardcoded example. In reality, there must be a "loadLevel" function that reads the level from a file.
	//in reality this floor must be a fixed PhysicEntity, but since we still don't have textures, we leave it that way"
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(Utils::pixelsToMeters(Vector2<int>(0, 580)).x, Utils::pixelsToMeters(Vector2<int>(0, 600)).y);
	b2Body* groundBody = world->CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(800/PIXELS_METER, 20/PIXELS_METER);
	groundBody->CreateFixture(&groundBox, 0.0f);
	
	std::vector<Texture*> texturesBackground;
	texturesBackground.push_back(textureManager->getTexture(TextureManager::TEX_BACKGROUND));
	background.init(texturesBackground);

}

void Map::update() {
	background.update();
}

void Map::render(RenderWindow *window) {
	background.render(window);
}