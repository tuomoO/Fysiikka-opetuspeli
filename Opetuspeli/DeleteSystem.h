#pragma once

#include "System.h"
#include "SceneParent.h"
#include "Box2D.h"

class DeleteSystem : public System
{
public:
	DeleteSystem(b2World* world, SceneParent* scene);
	~DeleteSystem();

	void update(float dt, GameObject* obj);
	void setScene(SceneParent* scene);

private:
	b2World* mWorld;
	SceneParent* mCurrentScene;

};

