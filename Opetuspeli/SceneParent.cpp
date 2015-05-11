#include "SceneParent.h"
#include <algorithm>

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

void SceneParent::remove(GameObject* obj)
{
	Ite i = find(mGameObjects.begin(), mGameObjects.end(), obj);
	if (i != mGameObjects.end())
		mGameObjects.erase(i);
}