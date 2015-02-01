#pragma once
#include "Utils.h"
#include "AnimatedSprite.h"
#include "CollisionData.h"

class PhysicEntity {

public:
	PhysicEntity(void);
	~PhysicEntity(void);

	//BASIC OPERATIONS:
	void init(Texture *texture, Vector2<int> position, Vector2<int> size);
    
    /**Caution, userData can't be declared on the caller's stack, it has to be a class member*/
    void setPhysics(b2World *world, const std::vector<b2FixtureDef*>& fixtureDef, 
                    const std::vector<CollisionData*>& userData, bool fixedRotation, bool isStatic);
    
	//updates physics and return true if the object is out of bounds or destroyed
	bool update(float deltaTime);
    
    //draw this entity to the screen
	void render(RenderWindow *window);
    
	void destroy(b2World *world);
    
    /**Called when a collision with other physicsEntity happens. 
        Every PhyisicEntity should override this method to handle collisions.
        TODO: Collision masks?*/
    virtual void onCollisionBegin(CollisionData* thisData, CollisionData* otherData) {};
    virtual void onCollisionEnd(CollisionData* thisData, CollisionData* otherData) {};

	Vector2f getPosition();

	b2Body* body;
private:
	AnimatedSprite sprite;
};