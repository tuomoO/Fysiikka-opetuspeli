#include "PhysicsComponentFactory.h"


PhysicsComponentFactory::PhysicsComponentFactory(b2World* world)
	:mWorld(world)
{
}


PhysicsComponentFactory::~PhysicsComponentFactory()
{
}

PhysicsComponent* PhysicsComponentFactory::make(float posX, float posY, float velX, float velY, float mass)
{
	b2BodyDef bodyDef;
	bodyDef.position = b2Vec2(posX, posY);
	bodyDef.type = b2_dynamicBody;
	b2Body* body = mWorld->CreateBody(&bodyDef);
	return new PhysicsComponent(body, 32.0f, 32.0f, velX, velY, mass);
}
