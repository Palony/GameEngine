#include "GameObject.h"

void GameObject::setXY(float x, float y)
{
	cords.x = x;
	cords.y = y;
}

void GameObject::setX(float x)
{
	cords.x = x;
}

void GameObject::setY(float y)
{
	cords.y = y;
}

sf::Vector2f GameObject::getXY()
{
	return cords;
}

float GameObject::getX()
{
	return cords.x;
}

float GameObject::getY()
{
	return cords.y;
}
