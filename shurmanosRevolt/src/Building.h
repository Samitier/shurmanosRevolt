#include "Utils.h"
#include "Room.h"
#include "ImageUtils.h"


class Building {
public:
	Building(void);
	~Building(void);

	void init(Texture* tileset, int tilesize, const vector< vector<int> >& facadeTiles, const vector <vector <int> >& interiorTiles);
	void update(float detaTime);
	void render(RenderWindow* window);

private:
	//this is the image generated with the parsing of the tiles that will make the textures of the front/back walls of the rooms. 
	//Whenever a wall is destroyed we will modify the part of this image, and set it as texture of the room affected.
	Image facade; 
	Image interior;
	//this is the vector containing all the rooms
	vector<Room> rooms;

	//only for debugging
	Sprite sprite;
	Texture tex;
};