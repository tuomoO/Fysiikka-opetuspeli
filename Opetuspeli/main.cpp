#pragma once

#include "GameObject.h"
#include "RenderSystem.h"
#include "PhysicsSystem.h"
#include "TransformComponentFactory.h"
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

static float pulse(float x)
{
	return 0.5*(1 + sin(2 * 3.14159 * x));
}

int main()
{
	//window
	const int windowWidth = 1024;
	const int windowHeight = 720;
	RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "PhysicsGame", Style::Close);
	//window.setFramerateLimit(60u);

	//box2D
	b2Vec2 gravity(0.0, -1.0);
	b2World world(gravity);
	

	//systems
	RenderSystem renderSystem = RenderSystem(&window);
	PhysicsSystem physicsSystem = PhysicsSystem(&world, windowWidth, windowHeight);
	RenderComponentFactory renderFactory;
	TransformComponentFactory transformFactory;
	PhysicsComponentFactory physicsFactory(&world);

	srand(time(NULL));
	vector<GameObject*> gameObjects;
	using GoIt = vector<GameObject*>::iterator;
	for (int i = 0; i < 10; i++)
	{
		GameObject* go = new GameObject;
		go->add(renderFactory.make("koala.png", 30 + rand() % 200, 30 + rand() % 200));
		//go->add(transformFactory.make(rand() % windowWidth, rand() % windowHeight));
		go->add(physicsFactory.make(rand() % windowWidth, rand() % windowHeight,
			0, 0, (rand() % 1000 + 1) / 1000.0f));
		gameObjects.push_back(go);
	}

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
        window.clear();

		for (GoIt i = gameObjects.begin(); i != gameObjects.end(); i++)
		{
			physicsSystem.update(*i);
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

