#pragma once

#include "Scene.h"
#include "RenderComponentFactory.h"
#include "PhysicsComponentFactory.h"

#include "SFML\System\Vector2.hpp"
#include "Box2D.h"

class TestScene : public Scene
{
public:
	TestScene(float scale, b2World* world, int windowWidth, int windowHeight);
	~TestScene();
	void update(float deltaTime, Input* input, sf::RenderWindow* window);

private:
	void addGameObject(float x, float y);

	float mScale;
	PhysicsComponentFactory mPhysicsFactory;
	sf::Vector2i mWindowSize;

};

