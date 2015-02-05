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
	Wall wall1; Wall wall2; Wall wall3;
	wall1.init(back, Vector2<int>(coords.left, coords.top - 320 + WALL_WIDTH),Vector2<int>(WALL_WIDTH, coords.height-WALL_WIDTH), world);
	wall2.init(back, Vector2<int>(coords.left+coords.width-WALL_WIDTH, coords.top - 320+WALL_WIDTH), Vector2<int>(WALL_WIDTH, coords.height - WALL_WIDTH), world);
	wall3.init(back, Vector2<int>(coords.left, coords.top - 320), Vector2<int>(coords.width, WALL_WIDTH), world);

	walls.push_back(wall1);
	walls.push_back(wall2);
	walls.push_back(wall3);
}

void Room::update(float deltaTime) {
	for (Wall &wall : walls) {
		wall.update(deltaTime);
	}

}

void Room::render(RenderWindow* window) {
	window->draw(frontWall);
	for (Wall &wall : walls) {
		wall.render(window);
	}
	window->draw(backWall);
	
}