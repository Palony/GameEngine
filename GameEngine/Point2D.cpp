#include "Point2D.h"


void Point2D::setXY(float x, float y)
{
	cords.x = x;
	cords.y = y;
}

void Point2D::setX(float x)
{
	cords.x = x;
}

void Point2D::setY(float y)
{
	cords.y = y;
}

sf::Vector2f Point2D::getXY()
{
	return cords;
}

float Point2D::getX()
{
	return cords.x;
}

float Point2D::getY()
{
	return cords.y;
}

void Point2D::draw_point(sf::RenderWindow& window)
{
	primitiveRenderer.drawIncrementalLine(window, cords.x, cords.y, cords.x, cords.y);
}