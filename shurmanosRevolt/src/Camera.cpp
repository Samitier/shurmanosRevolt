#include "Camera.h"

Camera::Camera(void) {}
Camera::~Camera(void){}

//initialize a camera that follows the player playr. The x movement is limited by 0 and limitx
void Camera::init(RenderWindow* windw, PhysicEntity* playr, int limitx) {
	limitX = limitx;
	window = windw;
	player = playr;
	Vector2f center = player->getPosition();
	center.y -= Y_OFFSET;
	view = View(center, Vector2f(window->getSize().x, window->getSize().y));
	window->setView(view);
}

void Camera::update(float deltaTime) {
	Vector2f center = player->getPosition();
	center.y -= Y_OFFSET;
	if (center.x - SCREEN_WIDTH / 2 < 0) center.x = SCREEN_WIDTH / 2;
	else if (center.x + SCREEN_WIDTH / 2 > limitX) center.x = limitX - SCREEN_WIDTH / 2;
	view.setCenter(center);
	window->setView(view);
}

Vector2f Camera::getCenter() {
	return view.getCenter();
}