#pragma once

#include "PhysicsComponent.h"

class PhysicsComponentFactory
{
public:
	PhysicsComponentFactory();
	~PhysicsComponentFactory();

	PhysicsComponent* make(float velX, float velY, float mass);
};

