#pragma once

#include "GameObject.h"
#include "Input.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <vector>

class Scene
{
public:
	/// Set paused status.
	void setPaused(bool Paused) { paused = Paused; }
	bool getPaused() { return paused; }

	///  Should contain everything that needs to be updated.
	virtual void update(float deltaTime, Input* input, sf::RenderWindow* window) {};

	~Scene(); // Deconstructor is scene dependant.

	int getGameObjectCount();

	std::vector<GameObject*>* getGameObjects();

	void remove(GameObject* obj);

protected:
	/// We shouldn't ever need to create Scene directly.
	Scene() : paused(false) {};
	Scene(bool paused) : paused(paused) {};

	bool paused; // Update is skipped for scenes that are paused.

	std::vector<GameObject*> mGameObjects;
};