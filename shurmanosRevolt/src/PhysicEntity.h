#pragma once
#include "Utils.h"
#include "AnimatedSprite.h"

class PhysicEntity {

public:
	PhysicEntity(void);
	~PhysicEntity(void);

	//BASIC OPERATIONS:
	void init(Texture *texture, Vector2<int> position, Vector2<int> size);
	void setPhysics(b2World *world, std::vector<b2FixtureDef*> *fixtureDef, bool fixedRotation, bool isStatic);

	//updates physics and return true if the object is out of bounds or destroyed
	bool update();
	void render(RenderWindow *window);
	void destroy(b2World *world);

	b2Body* body;
private:
	AnimatedSprite sprite;
};