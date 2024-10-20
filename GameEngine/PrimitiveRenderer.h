#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <time.h>
#include <iostream>

#pragma once


class PrimitiveRenderer
{
public:
	sf::Vertex vertex;
	sf::RenderWindow window;



	void init(sf::RenderWindow& window);
	void drawIncrementalLine(sf::RenderWindow& window, float x0, float y0, float x1, float y1);  // New method




};