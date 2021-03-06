#pragma once

#include "Scene.h"
#include "RenderComponentFactory.h"
#include "PhysicsComponentFactory.h"

#include "SFML\System\Vector2.hpp"
#include "Box2D.h"

class FrictionScene : public Scene
{
public:
	FrictionScene(float angle, float scale, b2World* world, int windowWidth, int windowHeight);
	~FrictionScene();

	void update(float deltaTime, Input* input, sf::RenderWindow* window);

private:
	float mScale;
	PhysicsComponentFactory mPhysicsFactory;
	sf::Vector2i mWindowSize;
	bool mSetupState;
	sf::Font* mFont;
	sf::Text mText;
	float mFriction;
};

