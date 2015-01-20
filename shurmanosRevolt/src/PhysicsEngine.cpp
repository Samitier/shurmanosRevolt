#include "PhysicsEngine.h"

const float PhysicsEngine::GRAVITY_FORCE	=	-20.0f;

void PhysicsEngine::update() {
	world.Step(1.0/60.0, 6, 2);
}

b2World* PhysicsEngine::getWorld() {
	return &world;
}
