#include "Rectangle.h"
#include <algorithm>
#include <cmath>

Rectangle::Rectangle(float w0, float h0, float w1, float h1)
    : w0_init(w0), h0_init(h0), w1_init(w1), h1_init(h1)
{
    // Inicjalizacja bok�w prostok�ta
    side1.set_top(w0, h0);
    side1.set_bottom(w1, h0);

    side2.set_top(w1, h0);
    side2.set_bottom(w1, h1);

    side3.set_top(w1, h1);
    side3.set_bottom(w0, h1);

    side4.set_top(w0, h1);
    side4.set_bottom(w0, h0);
}

void Rectangle::draw(sf::RenderWindow& window)
{
    side1.draw_line(window);
    side2.draw_line(window);
    side3.draw_line(window);
    side4.draw_line(window);
}
void Rectangle::fall(sf::RenderWindow& window, float ty)
{
    // Przesuwamy prostok�t w d�
    side1.translation(0, ty);
    side2.translation(0, ty);
    side3.translation(0, ty);
    side4.translation(0, ty);

    // Zwi�kszamy k�t obrotu
    rotationAngle += 1.0f; 

    if (rotationAngle >= 360.0f)
        rotationAngle -= 360.0f;

    // szukamy �rodka
    float centerX = (side1.get_top().x + side2.get_top().x + side3.get_top().x + side4.get_top().x) / 4.0f;
    float centerY = (side1.get_top().y + side2.get_top().y + side3.get_top().y + side4.get_top().y) / 4.0f;

    // Rotacja bok�w
    side1.rotationXY(1.0f, centerX, centerY);
    side2.rotationXY(1.0f, centerX, centerY);
    side3.rotationXY(1.0f, centerX, centerY);
    side4.rotationXY(1.0f, centerX, centerY);

    // Pobieramy wysoko�� okna
    float windowHeight = window.getSize().y;

    // Znajdujemy maksymaln� wsp�rz�dn� y wierzcho�k�w prostok�ta
    float maxY = std::max({
        side1.get_top().y, side1.get_bottom().y,
        side2.get_top().y, side2.get_bottom().y,
        side3.get_top().y, side3.get_bottom().y,
        side4.get_top().y, side4.get_bottom().y
        });

    // Je�li prostok�t wyszed� poza doln� kraw�d� ekranu
    if (maxY > windowHeight)
    {
        resetPosition();
    }
}

void Rectangle::resetPosition()
{
    // Resetujemy bok�w
    side1.set_top(w0_init, h0_init);
    side1.set_bottom(w1_init, h0_init);

    side2.set_top(w1_init, h0_init);
    side2.set_bottom(w1_init, h1_init);

    side3.set_top(w1_init, h1_init);
    side3.set_bottom(w0_init, h1_init);

    side4.set_top(w0_init, h1_init);
    side4.set_bottom(w0_init, h0_init);

    // Reset k�ta
    rotationAngle = 0.0f;
}
