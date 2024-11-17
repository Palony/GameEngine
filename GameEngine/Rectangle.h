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

    // Wsp�rz�dne pocz�tkowe
    float w0_init, h0_init, w1_init, h1_init;

    // Wsp�rz�dne aktualne
    float w0, h0, w1, h1;

    // K�t obrotu
    float rotationAngle = 0.0f;

public:
    Rectangle(float w0, float h0, float w1, float h1);

    void draw(sf::RenderWindow& window);
    void fall(sf::RenderWindow& window, float ty);
    void resetPosition();
    void updatePoints();

    // Gettery dla wsp�rz�dnych pocz�tkowych
    float getW0() const;
    float getH0() const;
    float getW1() const;
    float getH1() const;
};