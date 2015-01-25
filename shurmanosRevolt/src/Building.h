#include "Utils.h"
#include "Room.h"

class Building {
public:
	Building(void);
	~Building(void);

	void init();
	void update(float detaTime);
	void render(RenderWindow* window);

private:
	//this is the image generated with the parsing of the tiles that will make the textures of the front/back walls of the rooms. 
	//Whenever a wall is destroyed we will modify the part of this image, and set it as texture of the room affected.
	Image facade; 
	Image backFacade;
	//this is the vector containing all the rooms
	std::vector<Room> rooms;
};