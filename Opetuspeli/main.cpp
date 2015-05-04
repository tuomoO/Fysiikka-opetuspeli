#pragma once

#include "SceneSys.h"
#include "GameObject.h"
#include "RenderSystem.h"
#include "PhysicsSystem.h"
#include "RenderComponentFactory.h"
#include "PhysicsComponentFactory.h"

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

int main()
{
	//window
	const int windowWidth = 1024;
	const int windowHeight = 720;
	RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "PhysicsGame", Style::Close);
	//window.setFramerateLimit(60u);

	//box2D
	b2Vec2 gravity(0.0, -0.1f);
	b2World world(gravity);
	

	//systems
	float scale = 75.0f;
	RenderSystem renderSystem = RenderSystem(&window, scale);
	PhysicsSystem physicsSystem = PhysicsSystem(&world, windowWidth / scale, windowHeight / scale);
	RenderComponentFactory renderFactory;
	PhysicsComponentFactory physicsFactory(&world);

	srand(time(NULL));
	vector<GameObject*> gameObjects;
	using GoIt = vector<GameObject*>::iterator;
	for (int i = 0; i < 30; i++)
	{
		float x = (250 + rand() % (windowWidth - 500)) / scale;
		float y = (windowHeight - rand() % 200) / scale;

		GameObject* go = new GameObject;
		go->add(renderFactory.make("koala.png"));
		go->add(physicsFactory.make(x, y, 1.0f, 1.0f, 0, 0, 0.1f));
		gameObjects.push_back(go);
	}
	GameObject* ground = new GameObject();
	ground->add(renderFactory.make());
	ground->add(physicsFactory.make(windowWidth / scale / 2.0f, 2.0f, windowWidth / scale / 2.0f, 1.0f,
		0, 0, 0.1f, b2BodyType::b2_staticBody));
	gameObjects.push_back(ground);

	//time
	LARGE_INTEGER startTime, endTime, frequency, milliSeconds;
	float dt = 1.0f / 60;

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

		for (GoIt i = gameObjects.begin(); i != gameObjects.end(); i++)
		{
			physicsSystem.stepWorld(dt);
			//physicsSystem.update(*i);
			renderSystem.draw(*i);
		}
		renderSystem.swapBuffers();

		//time
		QueryPerformanceCounter(&endTime);
		milliSeconds.QuadPart = endTime.QuadPart - startTime.QuadPart;
		milliSeconds.QuadPart *= 1000;
		dt = milliSeconds.QuadPart / static_cast<float>(frequency.QuadPart);
		stringstream deltaStream;
		stringstream framesStream;
		deltaStream.precision(2);
		deltaStream << setfill('0') << setw(5) << dt;
		framesStream << setfill('0') << setw(6) << (1.0f / dt) * 1000;
		window.setTitle("Delta time(ms): " + deltaStream.str() + " | fps: " + framesStream.str());
    }

	for (GoIt i = gameObjects.begin(); i != gameObjects.end(); i++)
	{
		delete *i;
	}

    return 0;
}


/* Example on using SceneSys

float deltaTime = 0.0f; 

Update:

deltaTime = clock.restart().asSeconds();	// deltaTime as seconds.
SceneSys::Update(deltaTime, event);			// Update opened scenes.
SceneSys::Draw(window);						// Draw scenes.

*/

