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
void Point2D::translation(sf::RenderWindow& window, float tx, float ty)
{

	float x2 = cords.x + tx;
	float y2 = cords.y + ty;

	primitiveRenderer.drawIncrementalLine(window, x2, y2, x2, y2);

}

void Point2D::rotation00(sf::RenderWindow& window, float alfa)
{
	float x0 = 400;
	float y0 = 300;
	alfa = alfa * M_PI / 180;

	float x2 = x0 + (cords.x - x0) * cos(alfa) - (cords.y - y0) * sin(alfa);

	float y2 = y0 + (cords.x - x0) * sin(alfa) + (cords.y - y0) * cos(alfa);
	primitiveRenderer.drawIncrementalLine(window, x2, y2, x2, y2);
}

void Point2D::rotationXY(sf::RenderWindow& window, float alfa, float x0, float y0)
{

	alfa = alfa * M_PI / 180;

	float x2 = x0 + (cords.x - x0) * cos(alfa) - (cords.y - y0) * sin(alfa);
	float y2 = y0 + (cords.x - x0) * sin(alfa) + (cords.y - y0) * cos(alfa);
	primitiveRenderer.drawIncrementalLine(window, x2, y2, x2, y2);

}

void Point2D::scaling00(sf::RenderWindow& window, float k)
{
	float x0 = 400;
	float y0 = 300;

	


	float x2 = cords.x * k + (1 - k) * x0;
	float y2 = cords.y * k + (1 - k) * y0;
	primitiveRenderer.drawIncrementalLine(window, x2, y2, x2, y2);


}

void Point2D::scalingXY(sf::RenderWindow& window, float k, float x0, float y0)
{


	float x2 = cords.x * k + (1 - k) * x0;
	float y2 = cords.y * k + (1 - k) * y0;
	primitiveRenderer.drawIncrementalLine(window, x2, y2, x2, y2);
}
