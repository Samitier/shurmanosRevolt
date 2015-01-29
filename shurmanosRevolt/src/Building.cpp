#include "Building.h"

Building::Building(void) {}
Building::~Building(void) {}

void Building::init(Texture* tileset, int tilesize, const vector< vector<int> >& facadeTiles, const vector <vector <int> >& interiorTiles) {
	ImageUtils::generateImageFromTiles(&facade, tileset, facadeTiles, tilesize);
	ImageUtils::generateImageFromTiles(&interior, tileset, interiorTiles, tilesize);

	//ony for debug
	tex.loadFromImage(facade);
	sprite.setTexture(tex);
	sprite.setPosition(0, -320);

}

void Building::render(RenderWindow* window){
	window->draw(sprite);
}


