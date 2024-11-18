#include "Triangle.h"
#include <algorithm>
#include <cmath>

Triangle::Triangle(float x0, float y0, float x1, float y1, float x2, float y2, sf::Color color)
    : x0_init(x0), y0_init(y0), x1_init(x1), y1_init(y1), x2_init(x2), y2_init(y2), fillColor(color)
{
    // Inicjalizacja wspó³rzêdnych pocz¹tkowych
    this->x0 = x0_init;
    this->y0 = y0_init;
    this->x1 = x1_init;
    this->y1 = y1_init;
    this->x2 = x2_init;
    this->y2 = y2_init;

    // Inicjalizacja segmentów linii
    side1.set_top(x0, y0);
    side1.set_bottom(x1, y1);

    side2.set_top(x1, y1);
    side2.set_bottom(x2, y2);

    side3.set_top(x2, y2);
    side3.set_bottom(x0, y0);
}

float Triangle::getX0() const {
    return x0;
}

float Triangle::getY0() const {
    return y0;
}

float Triangle::getX1() const {
    return x1;
}

float Triangle::getY1() const {
    return y1;
}

float Triangle::getX2() const {
    return x2;
}

float Triangle::getY2() const {
    return y2;
}

void Triangle::draw(sf::RenderWindow& window)
{
    // ZnajdŸ prostok¹t otaczaj¹cy trójk¹t
    int minX = static_cast<int>(std::floor(std::min({ x0, x1, x2 })));
    int maxX = static_cast<int>(std::ceil(std::max({ x0, x1, x2 })));
    int minY = static_cast<int>(std::floor(std::min({ y0, y1, y2 })));
    int maxY = static_cast<int>(std::ceil(std::max({ y0, y1, y2 })));

    // Iteruj po pikselach w prostok¹cie otaczaj¹cym
    for (int y = minY; y <= maxY; ++y)
    {
        for (int x = minX; x <= maxX; ++x)
        {
            // SprawdŸ, czy punkt (x, y) le¿y wewn¹trz trójk¹ta
            float alpha, beta, gamma;
            float denominator = ((y1 - y2) * (x0 - x2) + (x2 - x1) * (y0 - y2));

            if (denominator == 0)
                continue; // Unikaj dzielenia przez zero

            alpha = ((y1 - y2) * (x - x2) + (x2 - x1) * (y - y2)) / denominator;
            beta = ((y2 - y0) * (x - x2) + (x0 - x2) * (y - y2)) / denominator;
            gamma = 1.0f - alpha - beta;

            if (alpha >= 0 && beta >= 0 && gamma >= 0)
            {
                sf::Vertex pixel(sf::Vector2f(static_cast<float>(x), static_cast<float>(y)), fillColor);
                window.draw(&pixel, 1, sf::Points);
            }
        }
    }

    // Opcjonalnie rysuj boki trójk¹ta
    side1.draw_line(window);
    side2.draw_line(window);
    side3.draw_line(window);
}

void Triangle::fall(sf::RenderWindow& window, float ty)
{
    // Aktualizacja punktów przed translacj¹
    updatePoints();

    // Translacja
    side1.translation(0, ty);
    side2.translation(0, ty);
    side3.translation(0, ty);

    // Aktualizacja po³o¿enia wierzcho³ków po translacji
    updatePoints();

    // Rotacja
    rotationAngle += 1.0f;
    if (rotationAngle >= 360.0f)
        rotationAngle -= 360.0f;

    // Wspó³rzêdne œrodka masy trójk¹ta
    float centerX = (x0 + x1 + x2) / 3.0f;
    float centerY = (y0 + y1 + y2) / 3.0f;

    // Rotacja wokó³ œrodka masy
    side1.rotationXY(1.0f, centerX, centerY);
    side2.rotationXY(1.0f, centerX, centerY);
    side3.rotationXY(1.0f, centerX, centerY);

    // Aktualizacja punktów po rotacji
    updatePoints();

    // Sprawdzanie, czy trójk¹t przekroczy³ ekran
    float windowHeight = window.getSize().y;
    float maxY = std::max({ y0, y1, y2 });

    if (maxY > windowHeight)
    {
        resetPosition(); // Jeœli trójk¹t opuœci³ ekran, resetuj pozycjê
        updatePoints();
    }
}

void Triangle::resetPosition()
{
    // Przywrócenie pocz¹tkowej pozycji wierzcho³ków
    side1.set_top(x0_init, y0_init);
    side1.set_bottom(x1_init, y1_init);

    side2.set_top(x1_init, y1_init);
    side2.set_bottom(x2_init, y2_init);

    side3.set_top(x2_init, y2_init);
    side3.set_bottom(x0_init, y0_init);

    // Resetowanie k¹ta obrotu
    rotationAngle = 0.0f;

    // Aktualizacja punktów
    updatePoints();
}

void Triangle::updatePoints()
{
    // Aktualizowanie bie¿¹cych pozycji wierzcho³ków na podstawie pozycji linii
    x0 = side1.get_top().x;
    y0 = side1.get_top().y;

    x1 = side2.get_top().x;
    y1 = side2.get_top().y;

    x2 = side3.get_top().x;
    y2 = side3.get_top().y;
}
