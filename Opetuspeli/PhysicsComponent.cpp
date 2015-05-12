#include "PhysicsComponent.h"

using namespace sf;

PhysicsComponent::PhysicsComponent(b2Body* body, float sizeX, float sizeY, float density, float friction)
	:mBody(body), mSize(sizeX, sizeY), mDensity(density), mFriction(friction)
{
	mShape.SetAsBox(sizeX / 2.0f, sizeY / 2.0f);
	b2FixtureDef fixtureDef;
	fixtureDef.density = density;
	fixtureDef.friction = friction;
	fixtureDef.shape = &mShape;
	mBody->CreateFixture(&fixtureDef);
}


PhysicsComponent::~PhysicsComponent()
{
}
