#pragma once

#include "GameObject.h"

class System
{
public:
	System();
	virtual ~System() = 0;
	virtual void update(float dt, GameObject* obj) = 0;

private:
};

