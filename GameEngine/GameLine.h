#pragma once
#include <iostream>
#include "Point2D.h"
#include "Player.h"
#include "PrimitiveRenderer.h"
#include "TransformableObject.h"
#include "DrawableObject.h"

#define M_PI 3.14159265358979323846

class GameLine :public TransformableObject,Player
{
	Point2D point;
	vector<Point2D> curve;
	const float angle=5.0f;
public:

	GameLine(float speed, float x, float y) {
		setXY(x, y);
		this->speed=speed;

		
	}
	float getAngle();
	void curveAlgorithm();
	void handleInput(const sf::RenderWindow& window) override;


	
};

