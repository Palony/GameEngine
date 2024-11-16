
#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "PrimitiveRenderer.h"
#include "LineSegment.h"


class Triangle : public DrawableObject, TransformableObject
{
    LineSegment side1;
    LineSegment side2;
    LineSegment side3;


    float rotationAngle = 0.0f; 
    float x0_init, y0_init, x1_init, y1_init, x2_init, y2_init;

public:
    Triangle(float x0, float y0, float x1, float y1, float x2, float y2)
        : x0_init(x0), y0_init(y0), x1_init(x1), y1_init(y1), x2_init(x2), y2_init(y2)
    {
        side1.set_top(x0, y0);
        side1.set_bottom(x1, y1);

        side2.set_top(x1, y1);
        side2.set_bottom(x2, y2);

        side3.set_top(x2, y2);
        side3.set_bottom(x0, y0);
    }

    void draw(sf::RenderWindow& window);
    void fall(sf::RenderWindow& window, float ty);
    void resetPosition();
};
