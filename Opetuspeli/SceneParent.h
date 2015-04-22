#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class SceneParent
{
public:
	/// Set paused status.
	void SetPaused(bool Paused) { paused = Paused; }
	bool GetPaused() { return paused; }

	///  Should contain everything that needs to be updated.
	virtual void Update(float deltaTime, sf::Event &events) {};

	/// Should contain everything that needs to be drawn.
	virtual void Draw(sf::RenderWindow &window) {};

	virtual ~SceneParent() {}; // Deconstructor is scene dependant.

protected:
	/// We shouldn't ever need to create SceneParent directly.
	SceneParent() : paused(false) {};
	SceneParent(bool paused) : paused(paused) {};

	bool paused; // Update is skipped for scenes that are paused.
};