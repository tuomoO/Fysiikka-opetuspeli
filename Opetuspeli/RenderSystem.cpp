#include "RenderSystem.h"

using namespace sf;
using namespace std;

RenderSystem::RenderSystem(RenderWindow* window, float scale)
	:mWindow(window), mScale(scale)
{
}


RenderSystem::~RenderSystem()
{
}


void RenderSystem::update(float dt, GameObject* gameObject)
{
	RenderComponent* render = gameObject->getComponent<RenderComponent>();
	if (render != nullptr)
	{
		RectangleShape shape = *render->getDrawable();
		PhysicsComponent* physics = gameObject->getComponent<PhysicsComponent>();
		if (physics != nullptr)
		{
			Vector2f position = mScale * flipY(physics->getBody()->GetPosition());
			shape.setPosition(position);
			shape.setSize(1.02f * mScale * physics->getSize());
			shape.setOrigin(shape.getSize() * 0.5f);

			// positive direction is opposite in Box2D
			shape.setRotation(-1.0f * physics->getBody()->GetAngle() * 180 / b2_pi);
		}
		mWindow->draw(shape);
	}
}


void RenderSystem::swapBuffers()
{
	mWindow->display();
}

Vector2f RenderSystem::flipY(b2Vec2 original)
{
	return Vector2f(original.x, mWindow->getSize().y / mScale - original.y);
}
