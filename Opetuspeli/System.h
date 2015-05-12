#pragma once

#include "GameObject.h"

class System
{
public:
	System();
	virtual ~System() = 0;
	virtual void update(float dt, std::vector<GameObject*>* objects) = 0;

private:
};

