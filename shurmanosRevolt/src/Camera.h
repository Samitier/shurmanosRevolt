#pragma once
#include "Utils.h"
#include "PhysicEntity.h"

class Camera {

public:
	Camera(void);
	~Camera(void);

	static const int Y_OFFSET = 182;

	//Basic operations
	void init(RenderWindow* window, PhysicEntity* player);
	void update();

private:
	View view;
	PhysicEntity* player;
	RenderWindow *window;
};

