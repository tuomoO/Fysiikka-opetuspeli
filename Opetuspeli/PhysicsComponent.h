#pragma once
#include "Component.h"
#include "Box2D.h"

class PhysicsComponent : public Component
{
	friend class PhysicsComponentFactory;
public:
	PhysicsComponent(float velX, float velY, float mass);
	~PhysicsComponent();

	b2Vec2 getVelocity() { return mVelocity; };
	float getMass() { return mMass; };

private:
	b2Vec2 mVelocity;
	float mMass;
};

