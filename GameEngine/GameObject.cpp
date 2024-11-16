#include "GameObject.h"

void GameObject::setXY(float x, float y)
{
	this->cords.x = x;
	this->cords.y = y;
}

void GameObject::setX(float x)
{
	this->cords.x = x;
}

void GameObject::setY(float y)
{
	this->cords.y = y;
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
