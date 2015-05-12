#include "SceneSys.h"
std::vector<Scene*> SceneSys::currentScenes;
bool SceneSys::sceneChanged;

void SceneSys::update(const float deltaTime, Input* input)
{
	for (std::vector<Scene*>::iterator it = currentScenes.begin(); it != currentScenes.end(); it++)
	{
		if (!(*it)->getPaused()) // Update scene if it's not paused.
			(*it)->update(deltaTime, input);
		if (sceneChanged) // If amount of scenes changes during update the iterator breaks.
		{
			sceneChanged = false;
			break; // Exit update loop if amount of scenes changed.
		}
	}
}

void SceneSys::openScene(Scene* newScene)
{
	currentScenes.push_back(newScene);
	sceneChanged = true;
}

void SceneSys::changeScene(Scene *newScene)
{
	cleanScenes();
	openScene(newScene);
}

void SceneSys::cleanScenes()
{
	if (currentScenes.size() > 0)
	{
		for (std::vector<Scene*>::iterator it = currentScenes.begin(); it != currentScenes.end(); it++)
			delete (*it); // Delete every scene.
	}
	currentScenes.clear();
}

void SceneSys::closeCurrentScene()
{
	if (currentScenes.size() > 0)
	{
		delete currentScenes.back();
		currentScenes.pop_back();
		sceneChanged = true;
	}
}

Scene* SceneSys::getCurrentScene()
{
	if (currentScenes.empty())
		return nullptr;
	else
		return *currentScenes.begin();
}
