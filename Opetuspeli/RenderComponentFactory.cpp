#include "RenderComponentFactory.h"

using namespace sf;

RenderComponentFactory::RenderComponentFactory()
{

}

RenderComponentFactory::~RenderComponentFactory()
{

}

RenderComponent* RenderComponentFactory::make(bool centerOrigin)
{
	return setShape(centerOrigin);
}

RenderComponent* RenderComponentFactory::make(std::string texturePath, bool centerOrigin)
{
	RenderComponent* result = setShape(centerOrigin);
	result->mTexture = new Texture();
	result->mTexture->loadFromFile(texturePath);
	result->mTexture->setSmooth(true);
	result->mShape.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
	result->mShape.setTexture(result->mTexture);

	return result;
}

RenderComponent* RenderComponentFactory::setShape(bool centerOrigin)
{
	RenderComponent* result = new RenderComponent();
	result->mShape = RectangleShape(Vector2f(1.0f, 1.0f));
	result->mShape.setPosition(0, 0);
	if (centerOrigin)
		result->mShape.setOrigin(0.5f, 0.5f);
	return result;
}