#pragma once

#include "PhysicsComponent.h"

class PhysicsComponentFactory
{
public:
	PhysicsComponentFactory(b2World* world);
	~PhysicsComponentFactory();

	PhysicsComponent* make(float posX, float posY, float sizeX, float sizeY,
		float velX, float velY, float mass, b2BodyType type = b2BodyType::b2_dynamicBody);

private:
	b2World* mWorld;
};

