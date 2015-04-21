#pragma once

#include "GameObject.h"

#include "Box2D.h"

class PhysicsSystem
{
public:
	PhysicsSystem(float gravityX, float gravityY, int windowWidth, int windowHeight);
	~PhysicsSystem();

	void update(GameObject* obj);

private:
	void checkWindowCollision(b2Vec2& position);

	b2Vec2 mGravity;
	b2Vec2 mWindowSize;
};

