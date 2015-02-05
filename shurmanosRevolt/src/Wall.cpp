#include "Wall.h"

Wall::Wall(void)
	: data((PhysicEntity*)this, ColliderTags::WALL) {}

Wall::~Wall(void){}

void Wall::init (Texture *texture, Vector2<int> position, Vector2<int> size, b2World *world) {
	PhysicEntity::init(texture, position, size);

	b2PolygonShape shape;
	shape.SetAsBox(size.x, size.y, b2Vec2(size.x / 2, -size.y/ 2), 0.0F); 
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 30.0f;
	fixtureDef.friction = 1.5f;
	setPhysics(world, { &fixtureDef }, { &data }, false, false);
}

void Wall::update(float deltaTime) {
	PhysicEntity::update(deltaTime);
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