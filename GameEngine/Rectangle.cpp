#include "Rectangle.h"
#include <algorithm>
#include <cmath>

Rectangle::Rectangle(float w0, float h0, float w1, float h1)
    : w0_init(w0), h0_init(h0), w1_init(w1), h1_init(h1)
{
    // Inicjalizacja wspó³rzêdnych pocz¹tkowych
    w0 = w0_init;
    h0 = h0_init;
    w1 = w1_init;
    h1 = h1_init;

    // Inicjalizacja boków prostok¹ta
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
    // Translacja prostok¹ta
    side1.translation(0, ty);
    side2.translation(0, ty);
    side3.translation(0, ty);
    side4.translation(0, ty);


    updatePoints(); // Aktualizacja wspó³rzêdnych po rotacji

    // Sprawdzanie, czy prostok¹t przekroczy³ ekran
    float windowHeight = window.getSize().y;
    float maxY = std::max({
        side1.get_top().y, side1.get_bottom().y,
        side2.get_top().y, side2.get_bottom().y,
        side3.get_top().y, side3.get_bottom().y,
        side4.get_top().y, side4.get_bottom().y
        });

    if (maxY > windowHeight)
    {
        resetPosition(); // Jeœli prostok¹t wyszed³ poza ekran, resetuj pozycjê
        updatePoints();
    }
}

void Rectangle::resetPosition()
{
    // Przywracanie pocz¹tkowej pozycji
    side1.set_top(w0_init, h0_init);
    side1.set_bottom(w1_init, h0_init);

    side2.set_top(w1_init, h0_init);
    side2.set_bottom(w1_init, h1_init);

    side3.set_top(w1_init, h1_init);
    side3.set_bottom(w0_init, h1_init);

    side4.set_top(w0_init, h1_init);
    side4.set_bottom(w0_init, h0_init);

    // Resetowanie k¹ta obrotu
    rotationAngle = 0.0f;
    updatePoints();
}

void Rectangle::updatePoints()
{
    // Aktualizowanie bie¿¹cych wspó³rzêdnych na podstawie pozycji boków
    w0 = side1.get_top().x;
    h0 = side1.get_top().y;

    w1 = side2.get_top().x;
    h1 = side2.get_top().y;
}

float Rectangle::getW0() const
{
    return w0;
}

float Rectangle::getH0() const
{
    return h0;
}

float Rectangle::getW1() const
{
    return w1;
}

float Rectangle::getH1() const
{
    return h1;
}