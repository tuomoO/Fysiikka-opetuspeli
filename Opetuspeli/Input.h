#pragma once

#include <SFML\Graphics.hpp>
#include <sstream>
#include <string>
#include <iomanip>
#include <map>

class Input
{
public:
	Input(sf::RenderWindow *window);
	~Input();

	void update();
	sf::Vector2i getMousePos(bool global = false);
	bool isM1Down();
	bool isM2Down();
	bool m1Click();
	bool m2Click();
	bool keyPress(sf::Keyboard::Key key);
	bool keyDown(sf::Keyboard::Key key);

private:
	sf::Vector2i mMousePos, mMousePosGlobal;
	bool mMouse1Down, mMouse2Down, mMouse1WasDown, mMouse2WasDown;
	sf::RenderWindow* mWindow;
	std::map<sf::Keyboard::Key, bool> mLastState;
};