#pragma once
#include "Utils.h"
#include "PhysicEntity.h"

#define MAX_JUMP_TIME = 1.0f

class Player:public PhysicEntity {

public:
    
    enum PlayerState {
        STATE_IDLE=0, STATE_WALK, STATE_JUMP
    };
    
	Player(void);
	~Player(void);


	static const int SPRITE_HEIGHT	=	95;
	static const int SPRITE_WIDTH	=	125;


	static const int PADDING_LEFT	= 0;
	static const int PADDING_RIGHT	= 0;
	static const int PADDING_TOP	= 0;
	static const int PADDING_BOTTOM = 0;
    

	//Basic operations
	void init(Texture *texture, Vector2<int> position, b2World *world);
	bool update();
	void render(RenderWindow *window);
	void destroy(b2World *world);

private:

    bool grounded;
    float midairTime;

};

