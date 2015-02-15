#include "Room.h"

Room::Room(void) {}
Room::~Room(void) {}

void Room::init(Texture *front, b2World* world, Texture *back, IntRect coords) {
	frontWall.setTexture(*front);
	backWall.setTexture(*back);
	frontWall.setTextureRect(coords);
	backWall.setTextureRect(coords);

	//this hardcoded 320 will not be necesary when the floor tiles will be implemented
	backWall.setPosition(coords.left, coords.top - 320);
	frontWall.setPosition(coords.left, coords.top - 320);

	//the wall texture must be set here instead "back"
	Wall wallLeft; Wall wallRight; Wall wallTop;
	wallLeft.init(back, Vector2<int>(coords.left, coords.top - 320 + WALL_WIDTH),Vector2<int>(WALL_WIDTH, coords.height), world);
	wallRight.init(back, Vector2<int>(coords.left+coords.width-WALL_WIDTH, coords.top - 320+WALL_WIDTH), Vector2<int>(WALL_WIDTH, coords.height), world);
	wallTop.init(back, Vector2<int>(coords.left, coords.top - 320), Vector2<int>(coords.width, WALL_WIDTH), world);

	walls.push_back(wallLeft);
	walls.push_back(wallRight);
	walls.push_back(wallTop);

	b2WeldJointDef jointDefLeft;
	jointDefLeft.bodyA = wallLeft.body;
	jointDefLeft.bodyB = wallTop.body;
	jointDefLeft.collideConnected = false;
	world->CreateJoint(&jointDefLeft);

	b2WeldJointDef jointDefRight;
	jointDefRight.bodyA = wallRight.body;
	jointDefRight.bodyB = wallTop.body;
	jointDefRight.collideConnected = false;
	//i don't like this, better create a joint class that works with pixel units
	jointDefRight.localAnchorB = b2Vec2(jointDefRight.localAnchorB.x+(coords.width-WALL_WIDTH)/PIXELS_METER, jointDefRight.localAnchorB.y);
	world->CreateJoint(&jointDefRight);

}

void Room::update(float deltaTime) {
	for (Wall &wall : walls) {
		wall.update(deltaTime);
	}
	//provisional: when walls[0] gets destroyed, this won't work
	frontWall.setPosition(Vector2f(walls[0].getPosition().x, walls[0].getPosition().y));
	frontWall.setRotation(walls[0].getRotation());
	backWall.setPosition(Vector2f(walls[0].getPosition().x, walls[0].getPosition().y));
	backWall.setRotation(walls[0].getRotation());
}

void Room::render(RenderWindow* window) {
	window->draw(backWall);
	/*for (Wall &wall : walls) {
		wall.render(window);
	}*/
	window->draw(frontWall);
}