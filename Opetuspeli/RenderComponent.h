#pragma once

#include "TransformComponent.h"

#include <SFML/Graphics.hpp>

#include <string>

class RenderComponent : public Component
{
	friend class RenderComponentFactory;

public:
    RenderComponent();
    ~RenderComponent();

	sf::RectangleShape* getDrawable();

private:
    sf::RectangleShape mShape;
	sf::Texture* mTexture;
};
