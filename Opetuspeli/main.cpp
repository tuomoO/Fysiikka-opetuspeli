#pragma once

#include "SceneSys.h"
#include "GameObject.h"
#include "RenderSystem.h"
#include "PhysicsSystem.h"
#include "RenderComponentFactory.h"
#include "PhysicsComponentFactory.h"
#include "TestScene.h"
#include "SystemManager.h"
#include "SceneSys.h"
#include "FrictionScene.h"
#include "Input.h"

#include "Box2D.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>
#include <time.h>
#include <Windows.h>
#include <sstream>
#include <iomanip>

using namespace std;
using namespace sf;

const float PI = 3.14159;

int main()
{
	srand(time(NULL));

	//window
	string message = "Opetuspeli";
	const int windowWidth = 1024;
	const int windowHeight = 720;
	RenderWindow window(sf::VideoMode(windowWidth, windowHeight), message, Style::Close);
	//window.setFramerateLimit(60u);
	Input input(&window);

	//box2D
	float scale = 75.0f;
	b2Vec2 gravity(0.0, -9.8f);
	b2World* world = new b2World(gravity);

	//scene
	SceneSys sceneSys;
	sceneSys.openScene(new TestScene(scale, world, windowWidth, windowHeight));

	//systems
	SystemManager systemManager;
	systemManager.add(new RenderSystem(&window, scale));
	systemManager.add(new PhysicsSystem(world, windowWidth / scale, windowHeight / scale));

	//time
	LARGE_INTEGER startTime, endTime, frequency, milliSeconds;
	float fpsTimer = 0;
	float dt = 1.0f / 60;
	int fps = 60;

    while (window.isOpen())
    {
		//time
		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&startTime);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(Color::White);

		//scene
		sceneSys.getCurrentScene()->update(dt, &input, &window);

		//input
		if (input.keyPress(Keyboard::Num1))
		{
			delete world;
			world = new b2World(gravity);
			sceneSys.changeScene(new TestScene(scale, world, windowWidth, windowHeight));
		}
		if (input.keyPress(Keyboard::Num2))
		{
			delete world;
			world = new b2World(gravity);
			sceneSys.changeScene(new FrictionScene(-0.12f * PI, scale, world, windowWidth, windowHeight));
		}
		if (input.keyPress(Keyboard::Num3))
		{
			delete world;
			world = new b2World(gravity);
			sceneSys.changeScene(new FrictionScene(-0.16f * PI, scale, world, windowWidth, windowHeight));
		}
		if (input.keyPress(Keyboard::Num4))
		{
			delete world;
			world = new b2World(gravity);
			sceneSys.changeScene(new FrictionScene(-0.19f * PI, scale, world, windowWidth, windowHeight));
		}


		input.update();
		
		systemManager.update(dt, sceneSys.getCurrentScene());
		world->Step(dt / 1000.0f, 8, 3);
		window.display();

		//time
		QueryPerformanceCounter(&endTime);
		milliSeconds.QuadPart = endTime.QuadPart - startTime.QuadPart;
		milliSeconds.QuadPart *= 1000;
		dt = milliSeconds.QuadPart / static_cast<float>(frequency.QuadPart);
		fpsTimer += dt;
		if (fpsTimer > 100)
		{
			fps = static_cast<int>(0.8f * fps + 0.2f * ((1.0f / dt) * 1000));
			stringstream framesStream;
			framesStream << setfill('0') << setw(4) << fps;
			stringstream objStream;
			objStream << setfill('0') << setw(3) << sceneSys.getCurrentScene()->getGameObjectCount();

			window.setTitle("[fps: " + framesStream.str() + "][GameObjects: " + objStream.str() + "] " + message);
			fpsTimer = 0;
		}
	}
	delete world;
    return 0;
}


/* Example on using SceneSys

float deltaTime = 0.0f; 

Update:

deltaTime = clock.restart().asSeconds();	// deltaTime as seconds.
SceneSys::Update(deltaTime, event);			// Update opened scenes.
SceneSys::Draw(window);						// Draw scenes.

*/

