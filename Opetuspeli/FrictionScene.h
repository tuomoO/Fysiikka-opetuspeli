#pragma once

#include "SceneParent.h"
#include "RenderComponentFactory.h"
#include "PhysicsComponentFactory.h"

#include "SFML\System\Vector2.hpp"
#include "Box2D.h"

class FrictionScene : public SceneParent
{
public:
	FrictionScene(float scale, b2World* world, int windowWidth, int windowHeight);
	~FrictionScene();

	void update(float deltaTime, sf::Event &events);

private:
	float mScale;
	PhysicsComponentFactory mPhysicsFactory;
	sf::Vector2i mWindowSize;

};

