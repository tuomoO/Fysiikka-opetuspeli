#pragma once

#include "PhysicsComponent.h"
#include "System.h"

#include "Box2D.h"

class PhysicsSystem : public System
{
public:
	PhysicsSystem(b2World* world, int windowWidth, int windowHeight);
	~PhysicsSystem();

	void update(float dt, std::vector<GameObject*>* objects);
	void stepWorld(float dt);

private:
	
	b2World* mWorld;
	b2Vec2 mWindowSize;
};

