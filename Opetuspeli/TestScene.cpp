#include "TestScene.h"


using namespace std;
using namespace sf;

TestScene::TestScene(float scale, b2World* world, int windowWidth, int windowHeight)
	: mScale(scale), mPhysicsFactory(world), mWindowSize(windowWidth, windowHeight)
{
	RenderComponentFactory renderFactory;
	for (int i = 0; i < 30; i++)
	{
		float x = (250 + rand() % (windowWidth - 500)) / scale;
		float y = (windowHeight + rand() % 400) / scale;
		addGameObject(x, y);
	}
	GameObject* ground = new GameObject();
	ground->add(renderFactory.make());
	ground->add(mPhysicsFactory.make(b2Vec2(windowWidth / mScale / 2.0f, 2.0f),
		windowWidth / mScale / 2.0f, 1.0f,
		1.0f, 0.25f, 0.0f, b2BodyType::b2_staticBody));
	mGameObjects.push_back(ground);
}


TestScene::~TestScene()
{
}

void TestScene::update(float deltaTime, Input* input, RenderWindow* window)
{
	if (input->keyDown(Keyboard::Space))
	{
		float x = (250 + rand() % (mWindowSize.x - 500)) / mScale;
		float y = (1.5f *  mWindowSize.y + rand() % mWindowSize.y) / mScale;
		addGameObject(x, y);
	}
}

void TestScene::addGameObject(float x, float y)
{
	RenderComponentFactory renderFactory;

	GameObject* go = new GameObject;
	go->add(renderFactory.make("koala.png"));
	go->add(mPhysicsFactory.make(b2Vec2(x, y), 1.0f, 1.0f, 1.0f, 0.25f));
	mGameObjects.push_back(go);
}