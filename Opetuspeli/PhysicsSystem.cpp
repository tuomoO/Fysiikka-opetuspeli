#include "PhysicsSystem.h"
#include "TransformComponent.h"
#include "PhysicsComponent.h"

#include "SFML\Graphics.hpp"
#include "Box2D\Dynamics\b2World.h"


PhysicsSystem::PhysicsSystem(b2World* world, int windowWidth, int windowHeight)
	:mWorld(world), mWindowSize(windowWidth, windowHeight)
{
	b2BodyDef groundBodyDef;
	groundBodyDef.position = b2Vec2(0, 0);
	//groundBodyDef.position = b2Vec2(X / 30.f, Y / 30.f);
	groundBodyDef.type = b2_staticBody;
	mGround = mWorld->CreateBody(&groundBodyDef);

	b2PolygonShape groundShape;
	groundShape.SetAsBox(windowWidth, 50.0f);
	b2FixtureDef groundFixtureDef;
	groundFixtureDef.density = 0.0f;
	groundFixtureDef.shape = &groundShape;
	mGround->CreateFixture(&groundFixtureDef);
}


PhysicsSystem::~PhysicsSystem()
{
	//delete mGround;
}

void PhysicsSystem::update(GameObject* obj)
{
	/*
	TransformComponent* transform = obj->getComponent<TransformComponent>();
	if (transform != nullptr)
	{
		 sf::Vector2f original = transform->getPosition();
		 b2Vec2 result(original.x, original.y);

		 PhysicsComponent* physics = obj->getComponent<PhysicsComponent>();
		 if (physics != nullptr)
		 {
			 result += physics->getVelocity();
			 result += physics->getMass() * mWorld->GetGravity();
		 }
		 checkWindowCollision(result);
		 

		 transform->setPosition(result.x, result.y);
	}
	*/

	PhysicsComponent* physics = obj->getComponent<PhysicsComponent>();
	if (physics != nullptr)
	{

	}
}

void PhysicsSystem::stepWorld(float dt)
{
	mWorld->Step(1/60.0f, 8, 3);
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
