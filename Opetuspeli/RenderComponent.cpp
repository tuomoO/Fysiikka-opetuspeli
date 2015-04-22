#include "RenderComponent.h"

using namespace sf;

RenderComponent::RenderComponent()
{
	mShape = RectangleShape();
	mTexture = nullptr;
}

RenderComponent::~RenderComponent()
{
	delete mTexture;
}

RectangleShape* RenderComponent::getDrawable()
{
	return &mShape;
}