#pragma once

#include "PhysicsComponent.h"

class PhysicsComponentFactory
{
public:
	PhysicsComponentFactory(b2World* world);
	~PhysicsComponentFactory();

	PhysicsComponent* make(float posX, float posY, float velX, float velY, float mass);

private:
	b2World* mWorld;
};

