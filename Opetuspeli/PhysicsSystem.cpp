#include "PhysicsSystem.h"
#include "TransformComponent.h"
#include "PhysicsComponent.h"

#include "SFML\Graphics.hpp"


PhysicsSystem::PhysicsSystem(float gravityX, float gravityY, int windowWidth, int windowHeight)
	:mGravity(gravityX, gravityY), mWindowSize(windowWidth, windowHeight)
{
}


PhysicsSystem::~PhysicsSystem()
{
}

void PhysicsSystem::update(GameObject* obj)
{
	TransformComponent* transform = obj->getComponent<TransformComponent>();
	if (transform != nullptr)
	{
		 sf::Vector2f original = transform->getPosition();
		 b2Vec2 result(original.x, original.y);

		 PhysicsComponent* physics = obj->getComponent<PhysicsComponent>();
		 if (physics != nullptr)
		 {
			 result += physics->getVelocity();
			 result += physics->getMass() * mGravity;
		 }
		 checkWindowCollision(result);
		 

		 transform->setPosition(result.x, result.y);
	}
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
