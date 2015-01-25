#include "Utils.h"
#include "PhysicEntity.h"

class Room {
public:
	Room(void);
	~Room(void);

	void init();
	void update(float detaTime);
	void render(RenderWindow* window);

private:
	//the sprite of the back and front wall. They will get the texture with the images of Building.
	Sprite frontWall;
	Sprite backWall;

	//the 4 walls that create a room
	std::vector<PhysicEntity> walls;
};