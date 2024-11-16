#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <iostream>

class GameObject
{
    sf::Vector2f cords;

public:
    virtual void setXY(float x, float y);
    virtual void setX(float x);
    virtual void setY(float y);
    virtual sf::Vector2f getXY();
    virtual float getX();
    virtual float getY();

};

