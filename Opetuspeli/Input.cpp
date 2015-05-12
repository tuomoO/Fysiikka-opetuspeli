#include "Input.h"

using namespace sf;
using namespace std;


Input::Input(RenderWindow *window)
	: mWindow(window)
{
	mMouse1Down = mMouse2Down = mMouse1WasDown = mMouse2WasDown = false;

	mMousePos = Mouse::getPosition(*window);
	mMousePosGlobal = Mouse::getPosition();

	for (int i = 0; i < Keyboard::KeyCount; i++)
	{
		mLastState.insert(make_pair<Keyboard::Key, bool>(
			static_cast<Keyboard::Key>(i), false));
	}
}


Input::~Input(void)
{
}


void Input::update()
{
	mMouse1WasDown = mMouse1Down;
	mMouse2WasDown = mMouse2Down;

	mMousePos = Mouse::getPosition(*mWindow);
	mMousePosGlobal = Mouse::getPosition();

	if (Mouse::isButtonPressed(Mouse::Left))
		mMouse1Down = true;
	else
		mMouse1Down = false;

	if (Mouse::isButtonPressed(Mouse::Right))
		mMouse2Down = true;
	else
		mMouse2Down = false;

	for (int i = 0; i < Keyboard::KeyCount; i++)
	{
		mLastState[static_cast<Keyboard::Key>(i)] 
			= Keyboard::isKeyPressed(static_cast<Keyboard::Key>(i));
	}
}


Vector2i Input::getMousePos(bool global)
{
	if (global)
		return mMousePosGlobal;
	else
		return mMousePos;
}


bool Input::isM1Down()
{
	return mMouse1Down;
}


bool Input::isM2Down()
{
	return mMouse2Down;
}


bool Input::m1Click()
{
	return !mMouse1WasDown && mMouse1Down;
}


bool Input::m2Click()
{
	return !mMouse2WasDown && mMouse2Down;
}

bool Input::keyPress(Keyboard::Key key)
{
	return (keyDown(key) && !mLastState[key]);
}

bool Input::keyDown(Keyboard::Key key)
{
	return Keyboard::isKeyPressed(key);
}
