#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "PrimitiveRenderer.h"
#include <cmath>

#pragma once

class Point2D
   {
private:
#define M_PI 3.14159265358979323846
    
    PrimitiveRenderer primitiveRenderer;
protected:
    sf::Vector2f cords;

public:


    virtual void setXY(float x, float y);
    void setX(float x);
    void setY(float y);
    virtual sf::Vector2f getXY();
    virtual float getX();
    virtual float getY();
    virtual void draw_point(sf::RenderWindow& window);
    virtual void translation(sf::RenderWindow& window, float tx, float ty);
    void rotation00(sf::RenderWindow& window, float alfa);   
    void rotationXY(sf::RenderWindow& window, float alfa, float x0, float y0);
    void scaling00(sf::RenderWindow& window, float k);
    void scalingXY(sf::RenderWindow& window, float k,float x0,float y0);
};

