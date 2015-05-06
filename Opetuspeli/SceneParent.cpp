#include "SceneParent.h"

using namespace std;
using Ite = vector<GameObject*>::iterator;

SceneParent::~SceneParent()
{
	for (Ite i = mGameObjects.begin(); i != mGameObjects.end(); i++)
	{
		delete(*i);
	}
	mGameObjects.clear();
}

int SceneParent::getGameObjectCount()
{
	return mGameObjects.size();
}

vector<GameObject*>* SceneParent::getGameObjects()
{
	return &mGameObjects;
}