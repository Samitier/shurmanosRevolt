#include "ContactListener.h"

void ContactListener::BeginContact(b2Contact* contact) {
    CollisionData* e1 = (CollisionData*) contact->GetFixtureA()->GetUserData();        
    CollisionData* e2 = (CollisionData*) contact->GetFixtureB()->GetUserData();        
       
    if(e1->entity) e1->entity->onCollisionBegin(e1,e2);
    if(e2->entity) e2->entity->onCollisionBegin(e2,e1);
}


void ContactListener::EndContact(b2Contact* contact) {
    CollisionData* e1 = (CollisionData*) contact->GetFixtureA()->GetUserData();        
    CollisionData* e2 = (CollisionData*) contact->GetFixtureB()->GetUserData();        
    
    if(e1->entity) e1->entity->onCollisionEnd(e1,e2);
    if(e2->entity) e2->entity->onCollisionEnd(e2,e1);
}
