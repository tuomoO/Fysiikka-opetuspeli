#include "RenderComponentFactory.h"

using namespace sf;

RenderComponentFactory::RenderComponentFactory()
{

}

RenderComponentFactory::~RenderComponentFactory()
{

}

RenderComponent* RenderComponentFactory::make(float x, float y, bool centerOrigin)
{
	return setShape(x, y, centerOrigin);
}

RenderComponent* RenderComponentFactory::make(std::string texturePath, float x, float y, bool centerOrigin)
{
	RenderComponent* result = setShape(x, y, centerOrigin);
	result->mTexture = new Texture();
	result->mTexture->loadFromFile(texturePath);
	result->mTexture->setSmooth(true);
	result->mShape.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));

	result->mShape.setTexture(result->mTexture);
	return result;
}

RenderComponent* RenderComponentFactory::setShape(float x, float y, bool centerOrigin)
{
	RenderComponent* result = new RenderComponent();
	result->mShape = RectangleShape(Vector2f(x, y));
	result->mShape.setPosition(0, 0);
	if (centerOrigin)
		result->mShape.setOrigin(x*0.5f, y*0.5f);
	return result;
}