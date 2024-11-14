#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"

class Circle :public DrawableObject, TransformableObject
{
	float R;
	sf::RenderWindow window;
public:
	Circle(float x, float y, float R)
	{
		this->setXY(x, y);
		this->R = R;
	}
	void draw(sf::RenderWindow& window);
	void drawQuarter(int x_sign, int y_sign, sf::RenderWindow& window);
	float getR();

};

