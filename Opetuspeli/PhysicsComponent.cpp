#include "PhysicsComponent.h"


PhysicsComponent::PhysicsComponent(float velX, float velY, float mass)
	:mVelocity(velX, velY), mMass(mass)
{
}


PhysicsComponent::~PhysicsComponent()
{
}
