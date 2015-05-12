#pragma once

#include "PhysicsComponent.h"

class PhysicsComponentFactory
{
public:
	PhysicsComponentFactory(b2World* world);
	~PhysicsComponentFactory();

	PhysicsComponent* make(b2Vec2 position, float sizeX, float sizeY,
		float density = 1.0f, float friction = 0.25f, float rotation = 0.0f, b2BodyType type = b2BodyType::b2_dynamicBody);

private:
	b2World* mWorld;
};

