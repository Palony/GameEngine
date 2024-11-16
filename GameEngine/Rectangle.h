#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "PrimitiveRenderer.h"
#include "LineSegment.h"

class Rectangle : public DrawableObject, TransformableObject
{
private:
    LineSegment side1;
    LineSegment side2;
    LineSegment side3;
    LineSegment side4;

    // Przechowywanie pocz¹tkowych pozycji
    float w0_init, h0_init, w1_init, h1_init;

    // K¹t obrotu
    float rotationAngle = 0.0f;

public:
    Rectangle(float w0, float h0, float w1, float h1);

    void draw(sf::RenderWindow& window);
    void fall(sf::RenderWindow& window, float ty);
    void resetPosition();


};
