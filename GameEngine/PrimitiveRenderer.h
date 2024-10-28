#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <time.h>
#include <iostream>
#include <cmath>

#pragma once


class PrimitiveRenderer
{
public:
	sf::Vertex vertex;
	sf::RenderWindow window;



	void init(sf::RenderWindow& window);
	void drawIncrementalLine(sf::RenderWindow& window, float x0, float y0, float x1, float y1);  
	void drawCircle(sf::RenderWindow& window, float x0, float y0, float R);
	void drawElipse(sf::RenderWindow& window, float x0, float y0, float R1, float R2);
	void drawQuarter(sf::RenderWindow& window, float x0, float y0, float R, int x_sign, int y_sign);
	void drawQuarterElipse(sf::RenderWindow& window, float x0, float y0, float R1,float R2, int x_sign, int y_sign);




};