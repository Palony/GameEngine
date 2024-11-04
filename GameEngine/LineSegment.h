#pragma once
#include "Point2D.h"
#include <cmath>

class LineSegment
{
#define M_PI 3.14159265358979323846
	Point2D top;
	Point2D bottom;
	PrimitiveRenderer primitiveRenderer;


public:
	void set_top(float x, float y);;
	void set_bottom(float x, float y);
	sf::Vector2f get_top();
	sf::Vector2f get_bottom();

	void draw_line(sf::RenderWindow& window);
	void translation(sf::RenderWindow& window, float tx, float ty);
	void rotation00(sf::RenderWindow& window, float alfa);
	void rotationXY(sf::RenderWindow& window, float alfa, float x0, float y0);
	void scaling00(sf::RenderWindow& window, float k);
	void scalingXY(sf::RenderWindow& window, float k, float x0, float y0);

};
