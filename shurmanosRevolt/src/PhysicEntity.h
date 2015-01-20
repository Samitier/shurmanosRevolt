#pragma once
#include "Includes.h"
#include "AnimatedSprite.h"

class PhysicEntity {

public:
	PhysicEntity(void);
	~PhysicEntity(void);

	//BASIC OPERATIONS:
	void init(Texture *texture, Vector2<int> position, Vector2<int> size, b2BodyDef bodyDef, std::vector<b2FixtureDef*> *fixtureDef, b2World *world);
	
	//updates physics and return true if the object is out of bounds or destroyed
	bool update();
	void render(RenderWindow *window);
	void destroy(b2World *world);


private:
	b2Body* body;
	AnimatedSprite sprite;
};