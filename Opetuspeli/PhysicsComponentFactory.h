#pragma once

#include "PhysicsComponent.h"

class PhysicsComponentFactory
{
public:
	PhysicsComponentFactory(b2World* world);
	~PhysicsComponentFactory();

	PhysicsComponent* make(float posX, float posY, float sizeX, float sizeY,
		float velX, float velY, float mass, float rotation = 0.0f, b2BodyType type = b2BodyType::b2_dynamicBody);

private:
	b2World* mWorld;
};

