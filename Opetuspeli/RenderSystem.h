#pragma once

#include <SFML/Graphics.hpp>
#include "RenderComponent.h"
#include "TransformComponent.h"
#include "GameObject.h"

class RenderSystem
{
public:
	RenderSystem(sf::RenderWindow* window);
	~RenderSystem();

	void draw(GameObject* gameObject);
	void swapBuffers();

private:
	sf::RenderWindow* mWindow;
};

