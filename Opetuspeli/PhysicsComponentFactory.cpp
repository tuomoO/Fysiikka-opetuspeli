#include "PhysicsComponentFactory.h"


PhysicsComponentFactory::PhysicsComponentFactory()
{
}


PhysicsComponentFactory::~PhysicsComponentFactory()
{
}

PhysicsComponent* PhysicsComponentFactory::make(float velX, float velY, float mass)
{
	return new PhysicsComponent(velX, velY, mass);
}
