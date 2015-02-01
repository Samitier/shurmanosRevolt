#pragma once
#include "Utils.h"
#include "PhysicEntity.h"

#define MAX_JUMP_TIME = 1.0f

class Player : public PhysicEntity {

public:
    
    enum PlayerState {
        STATE_IDLE=0, STATE_WALK, STATE_JUMP
    };
    
	Player(void);
	~Player(void);


	static const int SPRITE_HEIGHT	=	45;
	static const int SPRITE_WIDTH	=	25;


	static const int PADDING_LEFT	= 0;
	static const int PADDING_RIGHT	= 0;
	static const int PADDING_TOP	= 0;
	static const int PADDING_BOTTOM = 0;
    

	//Basic operations
	void init(Texture *texture, Texture* arm, Vector2<int> position, b2World *world);
	bool update(float deltaTime);
	void render(RenderWindow *window);
	void destroy(b2World *world);
    bool isGrounded() {return numContactsFloor > 0;}
    virtual void onCollisionBegin(CollisionData* thisData, CollisionData* otherData) override;
    virtual void onCollisionEnd(CollisionData* thisData, CollisionData* otherData) override;

private:

    int numContactsFloor = 0;
    float midairTime = 0;
    CollisionData bodyData, footData;
    AnimatedSprite arm;

};

