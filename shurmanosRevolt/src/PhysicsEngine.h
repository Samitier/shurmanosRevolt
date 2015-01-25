#pragma once
#include "Utils.h"

class PhysicsEngine {

public:
	static const float GRAVITY_FORCE;

	PhysicsEngine();
	~PhysicsEngine(void){}

	//BASIC OPERATIONS:
	void update(float deltaTime);
	b2World* getWorld();

private:
	b2World world;
};