#include "Building.h"

Building::Building(void) {}
Building::~Building(void) {}

void Building::init(Texture* tileset, b2World* world, int tilesize, const vector< vector<int> >& facadeTiles, const vector <vector <int> >& interiorTiles) {
	ImageUtils::generateImageFromTiles(&facade, tileset, facadeTiles, tilesize);
	ImageUtils::generateImageFromTiles(&interior, tileset, interiorTiles, tilesize);
	
	interiorTexture.loadFromImage(interior);
	facadeTexture.loadFromImage(facade);

	getRooms(tilesize, world, interiorTiles);

	//ony for debug
	tex.loadFromImage(interior);
	sprite.setTexture(tex);
	sprite.setPosition(0, -320);

}

void Building::getRooms(int tilesize, b2World* world, const vector< vector<int> >& tiles) {
	bool isRoom = false;
	int width = 0, ypos, xpos;
	for (int i = 0; i < tiles.size(); ++i) {
		for (int j = 0; j < tiles[i].size(); ++j) {
			if (tiles[i][j] == 0) continue;
			else if (tiles[i][j] == LEFT_WALL_TILE) {
				isRoom = true;
				ypos = i * tilesize;
				xpos = j*tilesize;
				width += tilesize;
			}
			else if (tiles[i][j] == MIDDLE_WALL_TILE && isRoom) width += tilesize;
			else if (tiles[i][j] == RIGHT_WALL_TILE && isRoom) {
				width += tilesize;
				isRoom = false;
				Room room;
				room.init(&facadeTexture, world, &interiorTexture, IntRect(xpos,ypos,width,tilesize));
				rooms.push_back(room);
				width =0;
			}
		}
	}
}

void Building::update(float deltaTime){
	for (Room &room : rooms) {
		room.update(deltaTime);
	}
}

void Building::render(RenderWindow* window){
	//window->draw(sprite);
	for (Room &room : rooms) {
		room.render(window);
	}
}


