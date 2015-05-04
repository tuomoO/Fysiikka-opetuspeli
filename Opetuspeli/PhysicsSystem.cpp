#include "PhysicsSystem.h"
#include "PhysicsComponent.h"

#include "SFML\Graphics.hpp"
#include "Box2D\Dynamics\b2World.h"


PhysicsSystem::PhysicsSystem(b2World* world, int windowWidth, int windowHeight)
	:mWorld(world), mWindowSize(windowWidth, windowHeight)
{

}


PhysicsSystem::~PhysicsSystem()
{

}

void PhysicsSystem::update(GameObject* obj)
{
	PhysicsComponent* physics = obj->getComponent<PhysicsComponent>();
	if (physics != nullptr)
	{

	}
}

void PhysicsSystem::stepWorld(float dt)
{
	//mWorld->Step(1/60.0f, 8, 3);
	mWorld->Step(dt / 1000.0f, 8, 3);
}

void PhysicsSystem::checkWindowCollision(b2Vec2& position)
{
	if (position.x < 0)
		position.x = 0;
	else if (position.x > mWindowSize.x)
		position.x = mWindowSize.x;

	if (position.y < 0)
		position.y = 0;
	else if (position.y > mWindowSize.y)
		position.y = mWindowSize.y;
}
