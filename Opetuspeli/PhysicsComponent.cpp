#include "PhysicsComponent.h"

using namespace sf;

PhysicsComponent::PhysicsComponent(b2Body* body, float sizeX, float sizeY, float velX, float velY, float mass)
	:mBody(body), mVelocity(velX, velY), mMass(mass), mSize(sizeX, sizeY)
{
	mShape.SetAsBox(sizeX / 2.0f, sizeY / 2.0f);
	b2FixtureDef fixtureDef;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.7f;
	fixtureDef.shape = &mShape;
	mBody->CreateFixture(&fixtureDef);
}


PhysicsComponent::~PhysicsComponent()
{
}
