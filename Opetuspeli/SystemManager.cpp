#include "SystemManager.h"

using namespace std;
using SIte = vector<System*>::iterator;

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
	for (SIte i = mSystems.begin(); i != mSystems.end(); i++)
	{
		(*i)->update(dt, scene->getGameObjects());
	}
}
