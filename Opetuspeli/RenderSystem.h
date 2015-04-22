#pragma once

#include <SFML/Graphics.hpp>
#include "RenderComponent.h"
#include "TransformComponent.h"
#include "PhysicsComponent.h"
#include "GameObject.h"

class RenderSystem
{
public:
	RenderSystem(sf::RenderWindow* window);
	~RenderSystem();

	void draw(GameObject* gameObject);
	void swapBuffers();

	sf::Vector2f flipY(b2Vec2 original);

private:
	sf::RenderWindow* mWindow;
};

