#pragma once
#include "Component.h"
#include "Box2D.h"
#include <SFML/Graphics.hpp>

class PhysicsComponent : public Component
{
	friend class PhysicsComponentFactory;
public:
	PhysicsComponent(b2Body* body, float sizeX, float sizeY, float Density, float friction);
	~PhysicsComponent();

	float getMass() { return mDensity * mSize.x * mSize.y; };
	float getFriction() { return mFriction; };
	b2Body* getBody() { return mBody; };
	b2PolygonShape* getShape() { return &mShape; };
	sf::Vector2f getSize() { return mSize; };
	
private:
	b2Body* mBody;
	b2PolygonShape mShape;
	float mFriction;
	float mDensity;
	sf::Vector2f mSize;
};

