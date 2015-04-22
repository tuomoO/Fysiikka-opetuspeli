#include "RenderSystem.h"

using namespace sf;
using namespace std;

RenderSystem::RenderSystem(RenderWindow* window)
	:mWindow(window)
{
}


RenderSystem::~RenderSystem()
{
}


void RenderSystem::draw(GameObject* gameObject)
{
	RenderComponent* render = gameObject->getComponent<RenderComponent>();
	if (render != nullptr)
	{
		RectangleShape shape = *render->getDrawable();
		PhysicsComponent* physics = gameObject->getComponent<PhysicsComponent>();
		if (physics != nullptr)
		{
			shape.setPosition(flipY(physics->getBody()->GetPosition()));
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
	return Vector2f(original.x, mWindow->getSize().y - original.y);
}
