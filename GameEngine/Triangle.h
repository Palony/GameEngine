#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "PrimitiveRenderer.h"
#include "LineSegment.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Triangle : public DrawableObject, TransformableObject
{
private:
    LineSegment side1;
    LineSegment side2;
    LineSegment side3;

    float rotationAngle = 0.0f;

    // Wspó³rzêdne pocz¹tkowe
    float x0_init, y0_init, x1_init, y1_init, x2_init, y2_init;

    // Wspó³rzêdne aktualne
    float x0, y0, x1, y1, x2, y2;

    // Kolor wype³nienia
    sf::Color fillColor;

public:
    Triangle(float x0, float y0, float x1, float y1, float x2, float y2, sf::Color color = sf::Color::White);

    // Gettery dla wspó³rzêdnych pocz¹tkowych
    float getX0() const;
    float getY0() const;
    float getX1() const;
    float getY1() const;
    float getX2() const;
    float getY2() const;

    // Metody rysowania, upadku i resetu
    void draw(sf::RenderWindow& window);
    void fall(sf::RenderWindow& window, float ty);
    void resetPosition();
    void updatePoints(); // Funkcja aktualizuje po³o¿enie wierzcho³ków
};
