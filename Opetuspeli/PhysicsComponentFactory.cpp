#include "PhysicsComponentFactory.h"


PhysicsComponentFactory::PhysicsComponentFactory(b2World* world)
	:mWorld(world)
{
}


PhysicsComponentFactory::~PhysicsComponentFactory()
{
}

PhysicsComponent* PhysicsComponentFactory::make(b2Vec2 position, float sizeX, float sizeY,
	float density, float friction, float rotation, b2BodyType type)
{
	b2BodyDef bodyDef;
	bodyDef.position = position;
	bodyDef.angle = rotation;
	bodyDef.type = type;
	return new PhysicsComponent(mWorld->CreateBody(&bodyDef), sizeX, sizeY, density, friction);
}
