#pragma once

#include "RenderComponent.h"

class RenderComponentFactory
{
public:
	RenderComponentFactory();
	~RenderComponentFactory();

	RenderComponent* make(float x, float y, bool centerOrigin = true);
	RenderComponent* make(std::string texturePath, float x, float y, bool centerOrigin = true);

private:
	RenderComponent* setShape(float x, float y, bool centerOrigin);

};