#include "Player.h"

Player::Player(void){}
Player::~Player(void){}




void Player::init(Texture *texture, Vector2<int> position, b2World *world) {
	PhysicEntity::init(texture, position, Vector2<int>(SPRITE_WIDTH, SPRITE_HEIGHT));
    float w = (SPRITE_WIDTH-PADDING_RIGHT)/PIXELS_METER;
    float h = (SPRITE_HEIGHT-PADDING_BOTTOM)/PIXELS_METER;

    b2PolygonShape footSensor;
    footSensor.SetAsBox(w/4,h/8,b2Vec2(w/2,-h*1.5),0.0F);
    b2FixtureDef footSensorDef;
    footSensorDef.shape = &footSensor;
    footSensorDef.isSensor = true;
    footSensorDef.density = 50;
    
    
    b2PolygonShape shape;
    shape.SetAsBox(w,h,b2Vec2(w/2,-h/2),0.0F); //The center has to be manually specified, otherwise it's (0,0)
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 30.0f;
    fixtureDef.friction = 1.5f;
    fixtureDef.isSensor = false;
    
	std::vector<b2FixtureDef*> fd;
	std::vector<ColliderTags> tags = { PLAYER_FOOT, PLAYER_BODY };
    fd.push_back(&footSensorDef);
	fd.push_back(&fixtureDef);
	setPhysics(world, &fd, &tags, false, false);
}

bool Player::update() {
    
	//Movement test
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
