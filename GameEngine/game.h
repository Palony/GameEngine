#pragma once
#include "Engine.h"


class game
{

	Triangle triangle;
	Rectangle rectangle;
	Circle circle;
	Player bitmap;
public:
	bool checkVertexCollisionWithBitmap(float px, float py, float bitmapX, float bitmapY, const sf::Image& bitmapImage);
	bool checkTriangleCollisionWithBitmap(const Triangle& triangle, Player& bitmap, const sf::Image& bitmapImage);
	bool checkPixelCollision(const Circle& circle, Player& bitmap, const sf::Image& bitmapImage);
	bool checkRectangleCollisionWithBitmap(const Rectangle& rectangle, Player& bitmap, const sf::Image& bitmapImage);
};

