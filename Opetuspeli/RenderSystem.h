#pragma once

#include "System.h"
#include "RenderComponent.h"
#include "PhysicsComponent.h"
#include <SFML/Graphics.hpp>


class RenderSystem : public System
{
public:
	RenderSystem(sf::RenderWindow* window, float scale);
	~RenderSystem();

	void update(float dt, std::vector<GameObject*>* objects);
	void swapBuffers();

	sf::Vector2f flipY(b2Vec2 original);

private:
	sf::RenderWindow* mWindow;
	float mScale;
};

