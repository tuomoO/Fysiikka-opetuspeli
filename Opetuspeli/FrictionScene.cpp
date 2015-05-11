#include "FrictionScene.h"

using namespace std;

FrictionScene::FrictionScene(float scale, b2World* world, int windowWidth, int windowHeight)
	: mScale(scale), mPhysicsFactory(world), mWindowSize(windowWidth, windowHeight)
{
	RenderComponentFactory renderFactory;
	using GoIt = vector<GameObject*>::iterator;

	GameObject* ground = new GameObject();
	ground->add(renderFactory.make());
	ground->add(mPhysicsFactory.make(windowWidth / mScale / 2.0f, 3.0f, 1.5f * windowWidth / mScale, 0.5f,
		0, 0, 0.1f, -35.0f, b2BodyType::b2_staticBody));
	mGameObjects.push_back(ground);
}


FrictionScene::~FrictionScene()
{
}

void FrictionScene::update(float deltaTime, sf::Event &events)
{
	
}