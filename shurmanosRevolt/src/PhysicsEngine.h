#pragma once
#include "Includes.h"

class PhysicsEngine {

public:
	PhysicsEngine(void);
	~PhysicsEngine(void);

	static const float GRAVITY_FORCE;

	//BASIC OPERATIONS:
	void init();

	b2World* getWorld();

private:
	b2World* world;
};