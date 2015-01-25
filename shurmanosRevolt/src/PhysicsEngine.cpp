#include "PhysicsEngine.h"
#include <iostream>
using namespace std;

const float PhysicsEngine::GRAVITY_FORCE	=	-20.0f;
PhysicsEngine::PhysicsEngine() :
  world(b2Vec2(0.0f, GRAVITY_FORCE)) {
     
}
void PhysicsEngine::update(float deltaTime) {
    cout << deltaTime << endl;
	world.Step(deltaTime, 6, 2);
}

b2World* PhysicsEngine::getWorld() {
	return &world;
}
