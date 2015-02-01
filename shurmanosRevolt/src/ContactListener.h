#pragma once
#include "Includes.h"
#include "PhysicEntity.h"

class ContactListener : public b2ContactListener {
    void BeginContact(b2Contact* contact);
    
    void EndContact(b2Contact* contact);
};