#pragma once

#include "RenderComponent.h"

class RenderComponentFactory
{
public:
	RenderComponentFactory();
	~RenderComponentFactory();

	RenderComponent* make();
	RenderComponent* make(std::string texturePath);

private:
	RenderComponent* setShape();
};