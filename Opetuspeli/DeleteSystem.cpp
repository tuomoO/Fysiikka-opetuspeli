#include "DeleteSystem.h"
#include "PhysicsComponent.h"

DeleteSystem::DeleteSystem(b2World* world, SceneParent* scene)
	: mWorld(world), mCurrentScene(scene)
{
}


DeleteSystem::~DeleteSystem()
{
}

void DeleteSystem::update(float dt, GameObject* obj)
{
	/*
	if (obj->isDeleted())
	{
		b2Body* body = obj->getComponent<PhysicsComponent>()->getBody();
		if (!mWorld->IsLocked())
			mWorld->DestroyBody(body);
		mCurrentScene->remove(obj);
	}
	*/
}

void DeleteSystem::setScene(SceneParent* scene)
{
	mCurrentScene = scene;
}