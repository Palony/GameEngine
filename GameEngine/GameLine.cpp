#include "GameLine.h"

float GameLine::getAngle()
{
	return this->angle;
}


void GameLine::curveAlgorithm()
{
	float x, y;
	float alfa = getAngle() * M_PI / 180;

	x = getX();
	y = getY();

	//x = speed*

}

void GameLine::handleInput(const sf::RenderWindow& window)//x, y, predkosc,
{

}
