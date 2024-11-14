#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "PrimitiveRenderer.h"

class Rectangle :public DrawableObject, TransformableObject
{
	float w0;
	float w1;
	float h0;
	float h1;


public:
	Rectangle(float w0, float w1, float h0, float h1) {
		this->w0 = w0;
		this->w1 = w1;
		this->h0 = h0;
		this->h1 = h1;
	}
	PrimitiveRenderer primitiveRenderer;
	void draw(sf::RenderWindow& window);
};

