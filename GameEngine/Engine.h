#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <time.h>
#include <iostream>


#pragma once



class Engine
{
public:

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Vector2i mousePos; //pozycja myszki
	sf::Event event; //zdarzenia
	sf::Clock clock; //zegar
	sf::Time time1;
	const bool running();



public:


	void initializeVariables();
	void initWindow();
	void update();
	void render();
	void handlingMouse();
	void polEvents();
	void time();

};