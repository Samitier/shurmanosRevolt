#include "PhysicsEngine.h"

const float PhysicsEngine::GRAVITY_FORCE	=	-20.0f;
PhysicsEngine::PhysicsEngine() :
  world(b2Vec2(0.0f, GRAVITY_FORCE)) {
    
    world.SetContactListener(&contactListener);
     
}
void PhysicsEngine::update(float deltaTime) {
	world.Step(deltaTime, 6, 2);
}

b2World* PhysicsEngine::getWorld() {
	return &world;
}
