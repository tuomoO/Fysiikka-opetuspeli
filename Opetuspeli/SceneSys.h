#pragma once
#include <vector>
#include "SceneParent.h"

class SceneSys
{
public:
	/// Draw all opened scenes.
	//static void Draw(sf::RenderWindow &window);

	/// Update all scenes that are not paused.
	static void update(float deltaTime, sf::Event &events);

	/// Open new scene over all previous scenes.
	static void openScene(SceneParent *newScene);

	/// Open new scene and delete all previous scenes.
	static void changeScene(SceneParent *newScene);

	/// Delete all scenes.
	static void cleanScenes();

	/// Delete scene that was opened last.
	static void closeCurrentScene();

	static SceneParent* getCurrentScene();

private:
	static std::vector<SceneParent*> currentScenes;	// Contains all opened scenes.
	static bool sceneChanged; // To prevent breaking the update iterator.
};

