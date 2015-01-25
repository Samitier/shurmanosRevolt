#pragma once
#include "Utils.h"


/*
	This class is for every animated sprite on the game. It needs the texture, the initial position of the sprite and the paddings. 
	The paddings are the pixel offset on the sprite in the collisions, so the picture shown fits well in it and there are no invisible spaces.
	The sprite size must be greater than the offset.
*/
class AnimatedSprite {

public:
	AnimatedSprite(void);
	~AnimatedSprite(void);

	static const int FRAME_DELAY	=	4;

	//BASIC OPERATIONS:
	void init(Texture *texture, Vector2<int> position, Vector2<int> size);
	void render(RenderWindow *window);

	sf::Vector2f getPosition();
	void setRotation(float angle);
	void setPosition(Vector2f position);
	Vector2<int> getSize() { return Vector2<int>(width, height); }
	//ANIMATION OPERATIONS:
	//nextFrame() calculates the actual frame and must be called once per render (if there is an animation running).
	//getFrame calculates the actual frame of the animation
	int getFrame();
	void nextFrame(int max);

private:
	Sprite sprite;

	int width, height;
	int frame;
	int delay;
};

