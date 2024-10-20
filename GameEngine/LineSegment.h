#pragma once
#include "Point2D.h"

class LineSegment
{
	Point2D top;
	Point2D bottom;
	PrimitiveRenderer primitiveRenderer;


public:
	void set_top(float x, float y);;
	void set_bottom(float x, float y);
	sf::Vector2f get_top();
	sf::Vector2f get_bottom();

	void draw_line(sf::RenderWindow& window);

};
