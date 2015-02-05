#pragma once
#include "Utils.h"
#include "PhysicEntity.h"

class Wall : public PhysicEntity {

	static const int WALL_WIDTH = 6;

public:
	Wall(void);
	~Wall(void);

	void init(Texture *texture, Vector2<int> position, Vector2<int> size, b2World *world);

	void update(float deltaTime);
	void render(RenderWindow *window);
	void destroy(b2World *world);

	virtual void onCollisionBegin(CollisionData* thisData, CollisionData* otherData) override;
	virtual void onCollisionEnd(CollisionData* thisData, CollisionData* otherData) override;

private:
	CollisionData data;
};