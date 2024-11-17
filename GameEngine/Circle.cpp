#include "Circle.h"
#include <cmath>

void Circle::draw(sf::RenderWindow& window)
{
    points.clear(); // Czy�� punkty przed narysowaniem ko�a
    drawQuarter(1, -1, window);
    drawQuarter(1, 1, window);
    drawQuarter(-1, 1, window);
    drawQuarter(-1, -1, window);
}

void Circle::drawQuarter(int x_sign, int y_sign, sf::RenderWindow& window)
{
    const float M_PI = 3.14159265359f; // PI
    float alfa = 0.0f; // k�t
    const float R = getR();
    const float inc = 1.0f / R; // stala kt�r� inkrementujemy k�t

    while (alfa <= M_PI / 2)
    {
        float x1 = getX() + x_sign * R * cos(alfa);
        float y1 = getY() + y_sign * R * sin(alfa);
        sf::Vector2f pos;
        pos.x = x1;
        pos.y = y1;
        addPoints(pos);


        sf::Vertex pixel(sf::Vector2f(std::round(x1), std::round(y1)), sf::Color::White);
        window.draw(&pixel, 1, sf::Points);

        alfa += inc;
    }
}

float Circle::getR()
{
    return R;
}

void Circle::fall(sf::RenderWindow& window, float ty)
{
  
    setY(getY() + ty);

  
    float windowHeight = window.getSize().y;

  
    if (getY() - R > windowHeight)
    {
        resetPosition();
    }
}

void Circle::resetPosition()
{
    points.clear(); // czy�ci wektor punkt�w
    setXY(initialX, -R); 
}


void Circle::addPoints(sf::Vector2f pos)
{
    this->points.push_back(pos);
   
}

std::vector<sf::Vector2f> Circle::getPoints()const
{
    return points;
}
