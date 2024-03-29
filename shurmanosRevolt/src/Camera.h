#pragma once
#include "Utils.h"
#include "PhysicEntity.h"


class Camera {

public:
	Camera(void);
	~Camera(void);

	//offset of the y axis for the camera
	static const int Y_OFFSET = 125;

	//Basic operations
	void init(RenderWindow* window, PhysicEntity* player, int limitX);
	void update(float deltaTime);
	Vector2f getCenter();

private:
	View view;
	PhysicEntity* player;
	RenderWindow *window;
	int limitX;
};

