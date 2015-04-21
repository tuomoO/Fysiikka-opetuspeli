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

		TransformComponent* transform = gameObject->getComponent<TransformComponent>();
		if (transform != nullptr)
		{
			shape.setPosition(transform->getPosition());
		}

		mWindow->draw(shape);
	}
}


void RenderSystem::swapBuffers()
{
	mWindow->display();
}
