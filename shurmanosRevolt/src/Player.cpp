#include "Player.h"

Player::Player(void) 
    : bodyData((PhysicEntity*)this, ColliderTags::PLAYER_BODY),
      footData ((PhysicEntity*)this, ColliderTags::PLAYER_FOOT) {}
      
Player::~Player(void){}




void Player::init(Texture* texture, Texture* armtex, Vector2<int> position, b2World *world) {
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
	std::vector<CollisionData*> tags = {&footData, &bodyData};
    fd.push_back(&footSensorDef);
	fd.push_back(&fixtureDef);
	setPhysics(world, fd, tags, true, false);
    
    arm.init(armtex, position, Vector2<int>(18,34),Vector2<int>(0,0));
}

bool Player::update(float deltaTime) {
    
    if(!isGrounded()) midairTime += deltaTime;
    if(!isGrounded() && !KEYPRESSED(Space)) midairTime += 0.5;
    
	//Movement test
	b2Vec2 direction = b2Vec2(0,body->GetLinearVelocity().y);
	if(KEYPRESSED(Left)) {
	    direction.x = -10;
	}
	if(KEYPRESSED(Right)) {
	    direction.x = 10;
	}
	if((isGrounded() || midairTime < 0.5) && KEYPRESSED(Space)) {
	    direction.y = 5;
	}
	body->SetLinearVelocity(direction);
	return PhysicEntity::update(deltaTime);
}

void Player::render(RenderWindow *window) {
    //Trigonometria! yay!
    static float rotation = 0;
    Vector2f c = window->getView().getCenter() - 0.5f*window->getView().getSize();
    Vector2f m = Vector2f(c.x+sf::Mouse::getPosition(*window).x,
                          c.y+sf::Mouse::getPosition(*window).y);
    Vector2f p = Vector2f(c.x+412,c.y+436);
    cout << m.x << " " << m.y << " | " << p.y << " " << p.y << endl;
    sf::Vertex line[] = {m,p};
    window->draw(line, 2, sf::Lines);
    
    rotation = atan2(m.y-p.y,m.x-p.x)*57.29-90;
    arm.setRotation(rotation);
    
    arm.setPosition(getPosition()+Vector2f(19,7));
	PhysicEntity::render(window);
    arm.render(window);
}

void Player::destroy(b2World *world) {
	PhysicEntity::destroy(world);
}

void Player::onCollisionBegin(CollisionData* thisData, CollisionData* otherData) {
    if(thisData->tag == ColliderTags::PLAYER_FOOT) {
        ++numContactsFloor;
        //TODO: numContactsFloor should always be positive 
        //for this to work. I should check that.
        midairTime = 0;
    }
}

void Player::onCollisionEnd(CollisionData* thisData, CollisionData* otherData) {
    if(thisData->tag == ColliderTags::PLAYER_FOOT) --numContactsFloor;
}