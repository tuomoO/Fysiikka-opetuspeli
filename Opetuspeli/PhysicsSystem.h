#pragma once

#include "GameObject.h"

#include "Box2D.h"

class PhysicsSystem
{
public:
	PhysicsSystem(b2World* world, int windowWidth, int windowHeight);
	~PhysicsSystem();

	void update(GameObject* obj);

private:
	void checkWindowCollision(b2Vec2& position);

	b2World* mWorld;
	b2Body* mGround;

	b2Vec2 mWindowSize;
};

