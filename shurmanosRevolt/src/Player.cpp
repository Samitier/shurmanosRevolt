#include "Player.h"

Player::Player(void){}
Player::~Player(void){}

void Player::init(Texture *texture, Vector2<int> position, b2World *world) {
	PhysicEntity::init(texture, position, Vector2<int>(SPRITE_WIDTH, SPRITE_HEIGHT));
	b2PolygonShape shape;
	shape.SetAsBox((SPRITE_WIDTH-PADDING_RIGHT)/PIXELS_METER,(SPRITE_HEIGHT-PADDING_BOTTOM)/PIXELS_METER);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 1.5f;
	std::vector<b2FixtureDef*> fd;
	fd.push_back(&fixtureDef);
	setPhysics(world,&fd, false, false);
}

bool Player::update() {
	return PhysicEntity::update();
}

void Player::render(RenderWindow *window) {
	PhysicEntity::render(window);
}

void Player::destroy(b2World *world) {
	PhysicEntity::destroy(world);
}
