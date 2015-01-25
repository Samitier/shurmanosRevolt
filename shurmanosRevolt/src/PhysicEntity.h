#pragma once
#include "Utils.h"
#include "AnimatedSprite.h"

class PhysicEntity {

public:
	PhysicEntity(void);
	~PhysicEntity(void);
    
    enum ColliderTags {
        COLLIDER_DEFAULT, PLAYER_BODY, PLAYER_FOOT
    };

	//BASIC OPERATIONS:
	void init(Texture *texture, Vector2<int> position, Vector2<int> size);
	void setPhysics(b2World *world, std::vector<b2FixtureDef*> *fixtureDef, std::vector<ColliderTags>* tags,
                    bool fixedRotation, bool isStatic);
    void setPhysics(b2World *world, std::vector<b2FixtureDef*> *fixtureDef, bool fixedRotation, bool isStatic);
    
	//updates physics and return true if the object is out of bounds or destroyed
	bool update(float deltaTime);
	void render(RenderWindow *window);
	void destroy(b2World *world);

	Vector2f getPosition();

	b2Body* body;
private:
	AnimatedSprite sprite;
};