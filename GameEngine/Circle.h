#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Circle : public DrawableObject, TransformableObject
{
private:
    float R;
    float speed;
    float initialX, initialY; // Pocz¹tkowe pozycje okrêgu
    std::vector<sf::Vector2f> points; // Wektor zawieraj¹cy punkty okrêgu
    sf::Color fillColor;      // Kolor wype³nienia

public:
    Circle(float x, float y, float R, sf::Color color = sf::Color::White);

    void draw(sf::RenderWindow& window);
    void drawQuarter(int x_sign, int y_sign, sf::RenderWindow& window);
    float getR();

    void fall(sf::RenderWindow& window, float ty);
    void resetPosition();
    void addPoints(sf::Vector2f pos);
    std::vector<sf::Vector2f> getPoints() const;
};
