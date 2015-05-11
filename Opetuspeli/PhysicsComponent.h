#pragma once
#include "Component.h"
#include "Box2D.h"
#include <SFML/Graphics.hpp>

class PhysicsComponent : public Component
{
	friend class PhysicsComponentFactory;
public:
	PhysicsComponent(b2Body* body, float sizeX, float sizeY,
		float velX, float velY, float mass);
	~PhysicsComponent();

	b2Vec2 getVelocity() { return mVelocity; };
	float getMass() { return mMass; };
	b2Body* getBody() { return mBody; };
	b2PolygonShape* getShape() { return &mShape; };
	sf::Vector2f getSize() { return mSize; };
	
private:
	b2Body* mBody;
	b2PolygonShape mShape;
	b2Vec2 mVelocity;
	float mMass;
	sf::Vector2f mSize;
};

