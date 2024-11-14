#include "Circle.h"

void Circle::draw(sf::RenderWindow& window)
{
    drawQuarter(1, -1, window);
    drawQuarter(1, 1, window);
    drawQuarter(-1, 1, window);
    drawQuarter(-1, -1, window);
}

void Circle::drawQuarter(int x_sign, int y_sign, sf::RenderWindow& window)
{
    const float M_PI = 3.14159265359f; // PI
    float alfa = 0.0f; // kat
    const float R = getR();
    const float inc = 1.0f / R; //stala któr¹ inkrementujemy k¹t

    while (alfa <= M_PI / 2)
    {
        float x1 = getX() + x_sign * R * cos(alfa);
        float y1 = getY() + y_sign * R * sin(alfa);

        sf::Vertex pixel(sf::Vector2f(std::round(x1), std::round(y1)), sf::Color::White);
        window.draw(&pixel, 1, sf::Points);

        alfa += inc;
    }
}

float Circle::getR()
{
    return R;
}
