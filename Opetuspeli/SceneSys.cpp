#include "SceneSys.h"
std::vector<SceneParent*> SceneSys::currentScenes;
bool SceneSys::sceneChanged;

void SceneSys::Draw(sf::RenderWindow &window)
{
	window.clear(sf::Color::Black); // Clear window.
	for (std::vector<SceneParent*>::iterator it = currentScenes.begin(); it != currentScenes.end(); it++)
		(*it)->Draw(window); // Draw scenes in order.
	window.display(); // Render scenes on screen.
}

void SceneSys::Update(const float deltaTime, sf::Event &events)
{
	for (std::vector<SceneParent*>::iterator it = currentScenes.begin(); it != currentScenes.end(); it++)
	{
		if (!(*it)->GetPaused()) // Update scene if it's not paused.
			(*it)->Update(deltaTime, events);
		if (sceneChanged) // If amount of scenes changes during update the iterator breaks.
		{
			sceneChanged = false;
			break; // Exit update loop if amount of scenes changed.
		}
	}
}

void SceneSys::OpenScene(SceneParent *newScene)
{
	currentScenes.push_back(newScene);
	sceneChanged = true;
}

void SceneSys::ChangeScene(SceneParent *newScene)
{
	CleanScenes();
	OpenScene(newScene);
}

void SceneSys::CleanScenes()
{
	if (currentScenes.size() > 0)
	{
		for (std::vector<SceneParent*>::iterator it = currentScenes.begin(); it != currentScenes.end(); it++)
			delete (*it); // Delete every scene.
	}
	currentScenes.clear();
}

void SceneSys::CloseCurrentScene()
{
	if (currentScenes.size() > 0)
	{
		delete currentScenes.back();
		currentScenes.pop_back();
		sceneChanged = true;
	}
}
