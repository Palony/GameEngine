#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"


class Circle : public DrawableObject, TransformableObject
{
private:
    float R;
    float speed; 
    float initialX, initialY; // Pocz¹tkowe pozycje okrêgu
    std::vector<sf::Vector2f> points; //Wektor zawieraj¹cy punkty okrêgu

public:
    Circle(float x, float y, float R)
    {
        this->setXY(x, y);
        this->R = R;
        this->speed = 1.0f; 

        
        this->initialX = x;
        this->initialY = y;
    }

    void draw(sf::RenderWindow& window);
    void drawQuarter(int x_sign, int y_sign, sf::RenderWindow& window);
    float getR();

    void fall(sf::RenderWindow& window, float ty);
    void resetPosition();
    void addPoints(sf::Vector2f pos);
    std::vector<sf::Vector2f> getPoints() const;
};
