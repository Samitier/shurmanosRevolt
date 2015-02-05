#pragma once

#include "Utils.h"
#include "PhysicEntity.h"

class PhysicEntity;

namespace Collision {
     enum ColliderTags {
        COLLIDER_DEFAULT, PLAYER_BODY, PLAYER_FOOT, WALL
    };   
}

typedef Collision::ColliderTags ColliderTags;

class CollisionData {
    
public: 
    

    
    CollisionData (PhysicEntity* _entity, ColliderTags _tag) {
        entity = _entity;
        tag = _tag;
    }
    
    PhysicEntity* entity;
    ColliderTags tag;
    
};