#pragma once

#include "System.h"
#include "SceneParent.h"
#include "GameObject.h"

#include <vector>

class SystemManager
{
public:
	SystemManager();
	~SystemManager();

	void add(System* system);
	void update(float dt, SceneParent*);

private:
	std::vector<System*> mSystems;
};

