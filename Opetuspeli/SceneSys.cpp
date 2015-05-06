#include "SceneSys.h"
std::vector<SceneParent*> SceneSys::currentScenes;
bool SceneSys::sceneChanged;

void SceneSys::update(const float deltaTime, sf::Event &events)
{
	for (std::vector<SceneParent*>::iterator it = currentScenes.begin(); it != currentScenes.end(); it++)
	{
		if (!(*it)->getPaused()) // Update scene if it's not paused.
			(*it)->update(deltaTime, events);
		if (sceneChanged) // If amount of scenes changes during update the iterator breaks.
		{
			sceneChanged = false;
			break; // Exit update loop if amount of scenes changed.
		}
	}
}

void SceneSys::openScene(SceneParent *newScene)
{
	currentScenes.push_back(newScene);
	sceneChanged = true;
}

void SceneSys::changeScene(SceneParent *newScene)
{
	cleanScenes();
	openScene(newScene);
}

void SceneSys::cleanScenes()
{
	if (currentScenes.size() > 0)
	{
		for (std::vector<SceneParent*>::iterator it = currentScenes.begin(); it != currentScenes.end(); it++)
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

SceneParent* SceneSys::getCurrentScene()
{
	if (currentScenes.empty())
		return nullptr;
	else
		return *currentScenes.begin();
}
