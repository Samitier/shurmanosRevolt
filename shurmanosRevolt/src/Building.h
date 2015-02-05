#include "Utils.h"
#include "Room.h"
#include "ImageUtils.h"


class Building {
public:
	Building(void);
	~Building(void);

	static const int LEFT_WALL_TILE = 4;
	static const int MIDDLE_WALL_TILE = 5;
	static const int RIGHT_WALL_TILE = 6;

	void init(Texture* tileset, b2World* world, int tilesize, const vector< vector<int> >& facadeTiles, const vector <vector <int> >& interiorTiles);
	void update(float detaTime);
	void render(RenderWindow* window);

private:
	void getRooms(int tilesize, b2World* world, const vector< vector<int> >& wallTiles);

	//this is the image generated with the parsing of the tiles that will make the textures of the front/back walls of the rooms. 
	//Whenever a wall is destroyed we will modify the part of this image, and set it as texture of the room affected.
	Image facade; 
	Image interior;

	Texture interiorTexture;
	Texture facadeTexture;
	//this is the vector containing all the rooms
	vector<Room> rooms;


	//only for debugging
	Sprite sprite;
	Texture tex;
};