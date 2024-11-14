#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"

class Elipse :public DrawableObject, TransformableObject
{
	float R1;
	float R2;
	sf::RenderWindow window;
public:
	Elipse(float x, float y, float R1, float R2) {
		this->setXY(x, y);
		this->R1 = R1;
		this->R2 = R2;
	}


	void draw(sf::RenderWindow& window);
	void drawQuarter(int x_sign, int y_sign, sf::RenderWindow& window);
	float getR1();
	float getR2();
};

