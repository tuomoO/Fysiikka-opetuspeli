#pragma once
#include <vector>
#include "SceneParent.h"

class SceneSys
{
public:
	/// Draw all opened scenes.
	static void Draw(sf::RenderWindow &window);

	/// Update all scenes that are not paused.
	static void Update(float deltaTime, sf::Event &events);

	/// Open new scene over all previous scenes.
	static void OpenScene(SceneParent *newScene);

	/// Open new scene and delete all previous scenes.
	static void ChangeScene(SceneParent *newScene);

	/// Delete all scenes.
	static void CleanScenes();

	/// Delete scene that was opened last.
	static void CloseCurrentScene();

private:
	static std::vector<SceneParent*> currentScenes;	// Contains all opened scenes.
	static bool sceneChanged; // To prevent breaking the update iterator.
};

