#include "Wall.h"

Wall::Wall(void)
	: data((PhysicEntity*)this, ColliderTags::WALL) {}

Wall::~Wall(void){}

void Wall::init (Texture *texture, Vector2<int> position, Vector2<int> size, b2World *world) {
	PhysicEntity::init(texture, position, size);
	float w = size.x / PIXELS_METER;
	float h = size.y / PIXELS_METER;
	b2PolygonShape shape;
	shape.SetAsBox(w/2, h/2, b2Vec2(w / 2, -h/ 2), 0.0F); 
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 30.0f;
	fixtureDef.friction = 1.5f;
	setPhysics(world, { &fixtureDef }, { &data }, false, false);
}

bool Wall::update(float deltaTime) {
	data.entity = (PhysicEntity*)this;
	PhysicEntity::updateCollisionData({ &data });
	return PhysicEntity::update(deltaTime);
}

void Wall::render(RenderWindow *window) {
	PhysicEntity::render(window);
}

void Wall::destroy(b2World *world) {
	PhysicEntity::destroy(world);
}

void Wall::onCollisionBegin(CollisionData* thisData, CollisionData* otherData) {

}

void Wall::onCollisionEnd(CollisionData* thisData, CollisionData* otherData) {

}