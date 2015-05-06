#pragma once

#include "PhysicsComponent.h"
#include "System.h"

#include "Box2D.h"

class PhysicsSystem : public System
{
public:
	PhysicsSystem(b2World* world, int windowWidth, int windowHeight);
	~PhysicsSystem();

	void update(float dt, GameObject* obj);
	void stepWorld(float dt);

private:
	bool checkWindowCollision(PhysicsComponent* physics);

	b2World* mWorld;
	b2Vec2 mWindowSize;
};

