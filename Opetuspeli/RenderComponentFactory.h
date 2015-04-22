#pragma once

#include "RenderComponent.h"

class RenderComponentFactory
{
public:
	RenderComponentFactory();
	~RenderComponentFactory();

	RenderComponent* make(bool centerOrigin = true);
	RenderComponent* make(std::string texturePath, bool centerOrigin = true);

private:
	RenderComponent* setShape(bool centerOrigin);
};