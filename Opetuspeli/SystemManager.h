#pragma once

#include "System.h"
#include "Scene.h"
#include "GameObject.h"

#include <vector>

class SystemManager
{
public:
	SystemManager();
	~SystemManager();

	void add(System* system);
	void update(float dt, Scene*);

private:
	std::vector<System*> mSystems;
};

