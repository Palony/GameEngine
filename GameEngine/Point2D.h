#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "PrimitiveRenderer.h"

#pragma once

class Point2D
{
private:
    sf::Vector2f cords;
    PrimitiveRenderer primitiveRenderer;

public:


    void setXY(float x, float y);
    void setX(float x);
    void setY(float y);
    sf::Vector2f getXY();
    float getX();
    float getY();
    void draw_point(sf::RenderWindow& window);
};

