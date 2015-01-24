#include "Camera.h"

Camera::Camera(void) {}
Camera::~Camera(void){}

void Camera::init(RenderWindow* windw, PhysicEntity* playr) {
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
	view.setCenter(center);
	window->setView(view);
}