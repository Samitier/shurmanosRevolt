#include "Map.h"


Map::Map(void)
    : groundData((PhysicEntity*)this, ColliderTags::COLLIDER_DEFAULT) {}
Map::~Map(void){}

void Map::init(TextureManager *textureManager,  b2World* world, Camera* cam) {
	//hardcoded example. In reality, there must be a "loadLevel" function that reads the level from a file.
	mapWidth = 2108; //the length of the floor
	floor.init(textureManager->getTexture(TextureManager::TEX_FLOOR),Vector2<int>(2108/2,SCREEN_HEIGHT-(22/2)),Vector2<int>(2108,22));
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
    std::vector<CollisionData*> data = {&groundData};
	floor.setPhysics(world,fd,data,true,true);
	
	std::vector<Texture*> texturesBackground;
	texturesBackground.push_back(textureManager->getTexture(TextureManager::TEX_BKG01));
	texturesBackground.push_back(textureManager->getTexture(TextureManager::TEX_BKG02));
	texturesBackground.push_back(textureManager->getTexture(TextureManager::TEX_BKG03));
	background.init(texturesBackground);

	camera = cam;

	//here begins 'the true level loader'. The width and the tiles of the floor must be retrieved from here too, not hardcoded like avobe
	LevelParser parser;
	parser.parseLevel("level0.json");
	building.init(textureManager->getTexture(TextureManager::TEX_TILESET), parser.getTileSize(), parser.getFacadeLayer(), parser.getInteriorLayer());

}

void Map::update(float deltaTime) {
	background.update(camera, mapWidth);
}

void Map::render(RenderWindow *window) {
	background.render(window);
	building.render(window);
	floor.render(window);
}