#pragma once
#include "Utils.h"

class PhysicsEngine {

public:
	static const float GRAVITY_FORCE;

	PhysicsEngine(void): world(b2Vec2(0.0f, GRAVITY_FORCE)){}
	~PhysicsEngine(void){}

	//BASIC OPERATIONS:
	void update();
	b2World* getWorld();

private:
	b2World world;
};