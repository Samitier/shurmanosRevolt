#include "AnimatedSprite.h"


AnimatedSprite::AnimatedSprite(void) {}
AnimatedSprite::~AnimatedSprite(void) {}


void AnimatedSprite::init(Texture *texture, Vector2<int> position, Vector2<int> size) {
	width = size.x;
	height = size.y;
	sprite.setTexture(*texture);
	sprite.setPosition(position.x,position.y);
	sprite.setOrigin(size.x/2, size.y/2);
	frame = delay = 0;
}


void AnimatedSprite::render(RenderWindow *window) {
	window->draw(sprite);
}

sf::Vector2f AnimatedSprite::getPosition() {
	return sprite.getPosition();
}

void AnimatedSprite::setRotation(float angle) {
	sprite.setRotation(angle);
}

void AnimatedSprite::setPosition(Vector2f pos) {
	sprite.setPosition(pos);
}

void AnimatedSprite::nextFrame(int max) {
	delay++;
	if(delay == FRAME_DELAY) {
		frame++;
		frame%=max;
		delay = 0;
	}
}

int AnimatedSprite::getFrame() {
	return frame;
}



