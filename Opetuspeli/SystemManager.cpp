#include "SystemManager.h"

using namespace std;
using SIte = vector<System*>::iterator;
using GIte = vector<GameObject*>::iterator;

SystemManager::SystemManager()
{
}


SystemManager::~SystemManager()
{
	for (SIte i = mSystems.begin(); i != mSystems.end(); i++)
	{
		delete(*i);
	}
	mSystems.clear();
}


void SystemManager::add(System* system)
{
	mSystems.push_back(system);
}

void SystemManager::update(float dt, Scene* scene)
{
	vector<GameObject*>* objects = scene->getGameObjects();
	for (SIte i = mSystems.begin(); i != mSystems.end(); i++)
	{
		for (GIte j = objects->begin(); j != objects->end(); j++)
		{
			(*i)->update(dt, (*j));
		}
	}
}
