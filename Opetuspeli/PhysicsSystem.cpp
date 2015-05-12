#include "PhysicsSystem.h"

#include "SFML\Graphics.hpp"
#include "Box2D\Dynamics\b2World.h"

using namespace std;
using Ite = vector<GameObject*>::iterator;

PhysicsSystem::PhysicsSystem(b2World* world, int windowWidth, int windowHeight)
	:mWorld(world), mWindowSize(windowWidth, windowHeight)
{

}


PhysicsSystem::~PhysicsSystem()
{

}

void PhysicsSystem::update(float dt, vector<GameObject*>* objects)
{
	for (Ite i = objects->begin(); i != objects->end();)
	{
		PhysicsComponent* physics = (*i)->getComponent<PhysicsComponent>();
		if (physics != nullptr)
		{
			if (physics->getBody()->GetPosition().y < 0)
			{
				b2Body* body = (*i)->getComponent<PhysicsComponent>()->getBody();
				if (!mWorld->IsLocked())
					mWorld->DestroyBody(body);
				delete (*i);
				i = objects->erase(i);
			}
			else
				i++;
		}
	}
	
}

void PhysicsSystem::stepWorld(float dt)
{
	mWorld->Step(dt / 1000.0f, 8, 3);
}
