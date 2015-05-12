#pragma once

#include "System.h"
#include "Scene.h"
#include "Box2D.h"

class DeleteSystem : public System
{
public:
	DeleteSystem(b2World* world, Scene* scene);
	~DeleteSystem();

	void update(float dt, GameObject* obj);
	void setScene(Scene* scene);

private:
	b2World* mWorld;
	Scene* mCurrentScene;

};

