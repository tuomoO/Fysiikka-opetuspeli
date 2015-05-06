#include "PhysicsSystem.h"

#include "SFML\Graphics.hpp"
#include "Box2D\Dynamics\b2World.h"


PhysicsSystem::PhysicsSystem(b2World* world, int windowWidth, int windowHeight)
	:mWorld(world), mWindowSize(windowWidth, windowHeight)
{

}


PhysicsSystem::~PhysicsSystem()
{

}

void PhysicsSystem::update(float dt, GameObject* obj)
{
	PhysicsComponent* physics = obj->getComponent<PhysicsComponent>();
	if (physics != nullptr)
	{
		/*
		if (checkWindowCollision(physics))
			obj->markForDelete();
			*/
	}
}

void PhysicsSystem::stepWorld(float dt)
{
	mWorld->Step(dt / 1000.0f, 8, 3);
}

bool PhysicsSystem::checkWindowCollision(PhysicsComponent* physics)
{
	if (physics->getBody()->GetPosition().y < 0)
	{
		mWorld->DestroyBody(physics->getBody());
		return true;
	}
	return false;
}
