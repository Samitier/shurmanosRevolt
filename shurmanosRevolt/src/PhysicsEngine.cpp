#include "PhysicsEngine.h"

const float PhysicsEngine::GRAVITY_FORCE	=	-20.0f;

PhysicsEngine::PhysicsEngine(void) {}
PhysicsEngine::~PhysicsEngine(void) {}


void PhysicsEngine::init() {
	b2Vec2 gravity = b2Vec2(0.0f, GRAVITY_FORCE);
	world = new b2World(gravity);
}

b2World* PhysicsEngine::getWorld() {
	return world;
}
