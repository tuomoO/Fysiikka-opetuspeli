#include "RenderComponentFactory.h"

using namespace sf;

RenderComponentFactory::RenderComponentFactory()
{

}

RenderComponentFactory::~RenderComponentFactory()
{

}

RenderComponent* RenderComponentFactory::make()
{
	return setShape();
}

RenderComponent* RenderComponentFactory::make(std::string texturePath)
{
	RenderComponent* result = setShape();
	result->mTexture = new Texture();
	result->mTexture->loadFromFile(texturePath);
	result->mTexture->setSmooth(true);
	result->mShape->setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
	result->mShape->setTexture(result->mTexture);

	return result;
}

RenderComponent* RenderComponentFactory::setShape()
{
	RenderComponent* result = new RenderComponent();
	result->mShape = new RectangleShape(Vector2f(1.0f, 1.0f));
	result->mShape->setPosition(0, 0);
	result->mShape->setFillColor(Color::Black);
	return result;
}