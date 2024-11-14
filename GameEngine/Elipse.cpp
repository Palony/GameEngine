#include "Elipse.h"

void Elipse::draw(sf::RenderWindow& window)
{
    drawQuarter(1, -1, window);
    drawQuarter(1, 1, window);
    drawQuarter(-1, 1, window);
    drawQuarter(-1, -1, window);

}

void Elipse::drawQuarter(int x_sign, int y_sign, sf::RenderWindow& window)
{
    const float M_PI = 3.14159265359f; // PI
    float alfa = 0.0f; // kat 
    float inc;

    float x0 = getX();
    float y0 = getY();
    float R1 = getR1();
    float R2 = getR2();

    //Ustawienie inc dla wiêkszego promienia
    if (R1 > R2) {
        inc = 1.0f / R1;
    }
    else {
        inc = 1.0f / R2;
    }

    while (alfa <= M_PI / 2)
    {
        float x = x0 + x_sign * R1 * cos(alfa);
        float y = y0 + y_sign * R2 * sin(alfa);

        sf::Vertex pixel(sf::Vector2f(std::round(x), std::round(y)), sf::Color::White);
        window.draw(&pixel, 1, sf::Points);

        alfa += inc;
    }
}

float Elipse::getR1()
{
    return this->R1;
}

float Elipse::getR2()
{
    return this->R2;
}
