#pragma once
#include <vector>
#include "Scene.h"

class SceneSys
{
public:
	/// Draw all opened scenes.
	//static void Draw(sf::RenderWindow &window);

	/// Update all scenes that are not paused.
	static void update(float deltaTime, Input* input);

	/// Open new scene over all previous scenes.
	static void openScene(Scene *newScene);

	/// Open new scene and delete all previous scenes.
	static void changeScene(Scene *newScene);

	/// Delete all scenes.
	static void cleanScenes();

	/// Delete scene that was opened last.
	static void closeCurrentScene();

	static Scene* getCurrentScene();

private:
	static std::vector<Scene*> currentScenes;	// Contains all opened scenes.
	static bool sceneChanged; // To prevent breaking the update iterator.
};

