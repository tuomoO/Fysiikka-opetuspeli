#include "TestScene.h"


using namespace std;

TestScene::TestScene(float scale, b2World* world, int windowWidth, int windowHeight)
	: mScale(scale), mPhysicsFactory(world), mWindowSize(windowWidth, windowHeight)
{
	RenderComponentFactory renderFactory;
	using GoIt = vector<GameObject*>::iterator;
	for (int i = 0; i < 30; i++)
	{
		float x = (250 + rand() % (windowWidth - 500)) / scale;
		float y = (windowHeight + rand() % 400) / scale;
		addGameObject(x, y);
	}
	GameObject* ground = new GameObject();
	ground->add(renderFactory.make());
	ground->add(mPhysicsFactory.make(windowWidth / mScale / 2.0f, 2.0f, windowWidth / mScale / 2.0f, 1.0f,
		0, 0, 0.1f, 0.0f, b2BodyType::b2_staticBody));
	mGameObjects.push_back(ground);
}


TestScene::~TestScene()
{
}

void TestScene::update(float deltaTime, sf::Event &events)
{
	float x = (250 + rand() % (mWindowSize.x - 500)) / mScale;
	float y = (mWindowSize.y + rand() % 400) / mScale;
	addGameObject(x, y);
}

void TestScene::addGameObject(float x, float y)
{
	RenderComponentFactory renderFactory;

	GameObject* go = new GameObject;
	go->add(renderFactory.make("koala.png"));
	go->add(mPhysicsFactory.make(x, y, 1.0f, 1.0f, 0, 0, 0.1f));
	mGameObjects.push_back(go);
}