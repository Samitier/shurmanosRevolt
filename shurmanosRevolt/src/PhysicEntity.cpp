#include "PhysicEntity.h"

PhysicEntity::PhysicEntity(void){}
PhysicEntity::~PhysicEntity(void){}

void PhysicEntity::init(Texture *tex, Vector2<int> pos, Vector2<int> siz){
	sprite.init(tex,pos,siz);
}

void PhysicEntity::setPhysics(b2World *world, const std::vector<b2FixtureDef*>& fixtureDef, 
                              const std::vector<CollisionData*>& userData, bool fixedRotation, bool isStatic){
	b2BodyDef bodyDef;
	if(!isStatic) bodyDef.type = b2_dynamicBody;
	bodyDef.fixedRotation = fixedRotation;
	b2Vec2 pos = Utils::pixelsToMeters(Vector2<int>(sprite.getPosition().x, sprite.getPosition().y));
	bodyDef.position.Set(pos.x, pos.y);
    //TODO: This line sometimes throws segmentation faults 
	body = world->CreateBody(&bodyDef);
	for(int i=0; i<fixtureDef.size();++i) {
        b2Fixture* fixture = body->CreateFixture(fixtureDef[i]);
        fixture->SetUserData((void*)(userData[i])); //Polymorphism at its finest
    }
}

void PhysicEntity::render(RenderWindow *window){
	sprite.render(window);
}

bool PhysicEntity::update(float deltaTime){
	b2Vec2 pos = body->GetPosition();
	sprite.setPosition(Utils::metersToPixels(pos));
	float32 rotation = body->GetAngle();
	sprite.setRotation(-rotation*57.295779);
	//if(sprite.getPosition().x > MAP_WIDTH +sprite.getSize().x || sprite.getPosition().x < 0-sprite.getSize().x) return true;
	//if(sprite.getPosition().y > MAP_HEIGHT+sprite.getSize().y || sprite.getPosition().y < -MAP_HEIGHT) return true;
	return false;
}

void PhysicEntity::updateCollisionData (const std::vector<CollisionData*>& userData) {
	int i = 0;
	for (b2Fixture* f = body->GetFixtureList(); f; f = f->GetNext()) {
		f->SetUserData(userData[i]);
		++i;
	}
}

Vector2f PhysicEntity::getPosition(){
	return sprite.getPosition();
}

float PhysicEntity::getRotation(){
	return sprite.getRotation();
}

void PhysicEntity::destroy(b2World *world) {
	world -> DestroyBody(body);
}
