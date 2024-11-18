#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "PrimitiveRenderer.h"
#include "LineSegment.h"
#include <SFML/Graphics.hpp> // Dodaj to, jeœli nie by³o wczeœniej

class Rectangle : public DrawableObject, TransformableObject
{
private:
    LineSegment side1;
    LineSegment side2;
    LineSegment side3;
    LineSegment side4;

    // Wspó³rzêdne pocz¹tkowe
    float w0_init, h0_init, w1_init, h1_init;

    // Wspó³rzêdne aktualne
    float w0, h0, w1, h1;

    // K¹t obrotu
    float rotationAngle = 0.0f;

    // Kolor wype³nienia
    sf::Color fillColor;

public:
    Rectangle(float w0, float h0, float w1, float h1, sf::Color color = sf::Color::White);

    void draw(sf::RenderWindow& window);
    void fall(sf::RenderWindow& window, float ty);
    void resetPosition();
    void updatePoints();

    // Gettery dla wspó³rzêdnych pocz¹tkowych
    float getW0() const;
    float getH0() const;
    float getW1() const;
    float getH1() const;
};
