#include "FrictionScene.h"
#include <sstream>

using namespace std;
using namespace sf;

FrictionScene::FrictionScene(float angle, float scale, b2World* world, int windowWidth, int windowHeight)
: mScale(scale), mPhysicsFactory(world), mWindowSize(windowWidth, windowHeight)
{
	RenderComponentFactory renderFactory;
	using GoIt = vector<GameObject*>::iterator;

	GameObject* ground = new GameObject();
	ground->add(renderFactory.make());
	ground->add(mPhysicsFactory.make(b2Vec2(windowWidth / mScale / 2.0f, 3.0f),
		1.5f * windowWidth / mScale, 0.5f,
		1.0f, 0.5f, angle, b2BodyType::b2_staticBody));
	mGameObjects.push_back(ground);
	
	mFont = new Font;
	mFont->loadFromFile("arial.ttf");
	mText.setFont(*mFont);
	mText.setCharacterSize(38);
	mText.setPosition(50, mWindowSize.y - 150);
	mText.setColor(Color::Black);
	mFriction = 0.25f;
}


FrictionScene::~FrictionScene()
{
	delete mFont;
}

void FrictionScene::update(float deltaTime, Input* input, RenderWindow* window)
{
	if (input->keyDown(Keyboard::Left))
		mFriction -= 0.0001f;
	if (input->keyDown(Keyboard::Right))
		mFriction += 0.0001f;
	if (mFriction < 0)
		mFriction = 0;

	if (input->keyPress(Keyboard::Space))
	{
		RenderComponentFactory renderFactory;
		GameObject* go = new GameObject;
		go->add(renderFactory.make("koala.png"));
		go->add(mPhysicsFactory.make(b2Vec2(1.0f, mWindowSize.y / mScale), 1.0f, 1.0f, 1.0f, mFriction));
		mGameObjects.push_back(go);
	}

	stringstream textStream;
	textStream << "Kitkakerroin: " << mFriction;
	mText.setString(textStream.str());
	window->draw(mText);
}