#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "PrimitiveRenderer.h"

class Triangle :public DrawableObject, TransformableObject
{
    float x0, x1, x2, y0, y1, y2;

    PrimitiveRenderer primitiveRenderer;

public:
    Triangle(float x0, float y0, float x1, float y1, float x2, float y2) {
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
    void draw(sf::RenderWindow& window);
};

