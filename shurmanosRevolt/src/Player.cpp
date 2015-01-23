#include "Player.h"

Player::Player(void){}
Player::~Player(void){}

void Player::init(Texture *texture, Vector2<int> position, b2World *world) {
	PhysicEntity::init(texture, position, Vector2<int>(SPRITE_WIDTH, SPRITE_HEIGHT));
	b2PolygonShape shape;
    //TODO I think all this should be done elsewhere
    float w = (SPRITE_WIDTH-PADDING_RIGHT)/PIXELS_METER;
    float h = (SPRITE_HEIGHT-PADDING_BOTTOM)/PIXELS_METER;
	shape.SetAsBox(w,h,b2Vec2(w/2,-h/2),0.0F); //The center has to be manually specified, otherwise it's (0,0)
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 1.5f;
	std::vector<b2FixtureDef*> fd;
	fd.push_back(&fixtureDef);
	setPhysics(world,&fd, false, false);
}

bool Player::update() {
	//Movement test
	body->SetLinearVelocity(b2Vec2(0,body->GetLinearVelocity().y));
	b2Vec2 direction = b2Vec2(0,body->GetLinearVelocity().y);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
	    direction.x = -20;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
	    direction.x = 20;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
	    direction.y = 20;
	}
	body->SetLinearVelocity(direction);
	return PhysicEntity::update();
}

void Player::render(RenderWindow *window) {
	PhysicEntity::render(window);
}

void Player::destroy(b2World *world) {
	PhysicEntity::destroy(world);
}
