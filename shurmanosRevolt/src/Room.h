#include "Utils.h"
#include "PhysicEntity.h"
#include "Wall.h"

class Room {
public:
	Room(void);
	~Room(void);

	static const int WALL_WIDTH = 6;


	void init(Texture * front, b2World* world, Texture* back, IntRect coords);
	void update(float detaTime);
	void render(RenderWindow* window);

private:
	//the sprite of the back and front wall. They will get the texture with the images of Building.
	Sprite frontWall;
	Sprite backWall;

	//the walls that create a room
	vector<Wall> walls;
};