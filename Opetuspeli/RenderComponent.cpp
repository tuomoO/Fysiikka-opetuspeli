#include "RenderComponent.h"

using namespace sf;

RenderComponent::RenderComponent()
{
	mShape = nullptr;
	mTexture = nullptr;
}

RenderComponent::~RenderComponent()
{
	delete mTexture;
	delete mShape;
}

RectangleShape* RenderComponent::getDrawable()
{
	return mShape;
}