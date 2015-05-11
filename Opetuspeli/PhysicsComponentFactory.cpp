#include "PhysicsComponentFactory.h"


PhysicsComponentFactory::PhysicsComponentFactory(b2World* world)
	:mWorld(world)
{
}


PhysicsComponentFactory::~PhysicsComponentFactory()
{
}

PhysicsComponent* PhysicsComponentFactory::make(float posX, float posY, float sizeX, float sizeY,
	float velX, float velY, float mass, float rotation, b2BodyType type)
{
	b2BodyDef bodyDef;
	bodyDef.position = b2Vec2(posX, posY);
	bodyDef.angle = rotation;
	bodyDef.type = type;
	return new PhysicsComponent(mWorld->CreateBody(&bodyDef), sizeX, sizeY, velX, velY, mass);
}
