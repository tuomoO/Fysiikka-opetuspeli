#include "Scene.h"
#include <algorithm>

using namespace std;
using Ite = vector<GameObject*>::iterator;

Scene::~Scene()
{
	for (Ite i = mGameObjects.begin(); i != mGameObjects.end(); i++)
	{
		delete(*i);
	}
	mGameObjects.clear();
}

int Scene::getGameObjectCount()
{
	return mGameObjects.size();
}

vector<GameObject*>* Scene::getGameObjects()
{
	return &mGameObjects;
}

void Scene::remove(GameObject* obj)
{
	Ite i = find(mGameObjects.begin(), mGameObjects.end(), obj);
	if (i != mGameObjects.end())
		mGameObjects.erase(i);
}